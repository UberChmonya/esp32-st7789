#include "Indicator.h" 

Indicator::Indicator(Adafruit_ST7789* Screen, circlePoint Circle, int SizeOfSector) : 
circle(Circle),
screen(Screen),
sizeOfSector(SizeOfSector),
pixelPercent((Circle.size - SizeOfSector) / 100.0){}

void Indicator::pixelForDeleteAndDraw(uint16_t startPixel) 
{
  reDrawCount = 0;
  if(startPixel == newStartSector) return;

  oldStartSector = newStartSector;
  newStartSector = startPixel;

  if(newStartSector > oldStartSector)
  {
    reDrawCount = newStartSector - oldStartSector;
    if(reDrawCount > sizeOfSector) reDrawCount = sizeOfSector;

    startDeletePixel = oldStartSector;
    startDrawPixel = newStartSector + sizeOfSector - reDrawCount;
    return;
}

  reDrawCount = oldStartSector - newStartSector;
  if(reDrawCount > sizeOfSector) reDrawCount = sizeOfSector;

  startDeletePixel = oldStartSector + sizeOfSector - reDrawCount;
  startDrawPixel = newStartSector;
}

void Indicator::deletePixel()
{
  for (int i = startDeletePixel; i < reDrawCount + startDeletePixel; i++)
  {
    screen->drawPixel(
        circle.massiveX[i],
        circle.massiveY[i],
        screen->color565(0, 0, 0));
  }
}

void Indicator::drawPixel()
{
  for (int i = startDrawPixel; i < reDrawCount + startDrawPixel; i++)
  {
    screen->drawPixel(
        circle.massiveX[i],
        circle.massiveY[i],
        screen->color565(255, 255, 255));
  }
}

void Indicator::newSector(uint16_t newStart)
{
  Serial.println(newStart);
  Serial.println(pixelPercent);

  pixelForDeleteAndDraw(newStart * pixelPercent);
  deletePixel();
  drawPixel();
}

#include "Indicator.h" 

Indicator::Indicator(Adafruit_ST7789* Screen, int* CirclePointX, int* CirclePointY, int const CircleSize, int SizeOfSector) : 
circleSize(CircleSize),
circlePointX(CirclePointX),
circlePointY(CirclePointY),
screen(Screen),
sizeOfSector(SizeOfSector){}

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
        circlePointX[i],
        circlePointY[i],
        screen->color565(0, 0, 0));
  }
}

void Indicator::drawPixel()
{
  for (int i = startDrawPixel; i < reDrawCount + startDrawPixel; i++)
  {
    screen->drawPixel(
        circlePointX[i],
        circlePointY[i],
        screen->color565(255, 255, 255));
  }
}

void Indicator::newSector(uint16_t newStart)
{
  pixelForDeleteAndDraw(newStart);
  deletePixel();
  drawPixel();
}

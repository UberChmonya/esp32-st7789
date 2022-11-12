#include "Indicator.h" 

Indicator::Indicator(uint16_t* CirclePointX, uint16_t* CirclePointY, uint16_t CircleSize, uint16_t SizeOfSector)
{
    circlePointX = *CirclePointX;
    circlePointY = *CirclePointY;
    circleSize = CircleSize;
    sizeOfSector = SizeOfSector;
}

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
    tft.drawPixel(
        circlePointX[i],
        circlePointY[i],
        tft.color565(0, 0, 0));
  }
}

void Indicator::drawPixel()
{
  for (int i = startDrawPixel; i < reDrawCount + startDrawPixel; i++)
  {
    tft.drawPixel(
        circlePointX[i],
        circlePointY[i],
        tft.color565(255, 255, 255));
  }
}

void Indicator::newSector(uint16_t newStart)
{
  pixelForDeleteAndDraw(newStart);
  deletePixel();
  drawPixel();
}

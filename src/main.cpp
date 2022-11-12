#include "main.h"

void setup(void)
{
  Serial.begin(115200);
  tft.init(TFT_WIDTH, TFT_HEIGHT);
  tft.setRotation(2);
  tft.fillScreen(tft.color565(0, 0, 0));
  
}

void test()
{
  while(true)
  {
    for(int i = 0; i <= circleSize1 - 30;i += 3)
    {
      indecator.newSector(i);
      delay(20);
    } 
    for(int i = circleSize1 - 30; i >= 0;i -= 3)
    {
      indecator.newSector(i);
      delay(20);
    } 
  }
}

void loop()
{
  test();
}

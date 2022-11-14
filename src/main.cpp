#include "main.h"

void setup(void)
{
  Serial.begin(115200);
  display.init(TFT_WIDTH, TFT_HEIGHT);
  display.setRotation(2);
  display.fillScreen(display.color565(0, 0, 0));
}

void test()
{
  while(true)
  {
    for(int i = 0; i <= 100;i += 2)
    {
      indecator2.newSector(i);
      delay(20);
    } 
    for(int i = 100; i >= 0;i -= 2)
    {
      indecator2.newSector(i);
      delay(20);
    } 
  }
}

void loop()
{
  test();
}

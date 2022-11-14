#pragma once
#include <Arduino.h>
#include <Adafruit_ST7789.h>
#include "circleStruct.h"
class Indicator
{
    private:
        circlePoint circle;
        Adafruit_ST7789* screen;

        void pixelForDeleteAndDraw(uint16_t startPixel);
        void deletePixel();
        void drawPixel();

        int startDeletePixel;
        int startDrawPixel;
        int reDrawCount;
        int oldStartSector;
        int newStartSector;
        int sizeOfSector;

        float pixelPercent;

    public:
        Indicator(
        Adafruit_ST7789* Screen, 
        circlePoint Circle, 
        int SizeOfSector);

        void newSector(uint16_t newStart);
};

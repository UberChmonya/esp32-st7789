#pragma once
#include <Arduino.h>
#include<Adafruit_GFX.h>
#include <Adafruit_ST7789.h>

class Indicator
{
    private:
        uint16_t startDeletePixel;
        uint16_t startDrawPixel;
        uint16_t reDrawCount;
        uint16_t oldStartSector;
        uint16_t newStartSector;
        uint16_t circleSize;
        uint16_t* circlePointX;
        uint16_t* circlePointY;
        uint16_t sizeOfSector;
        void pixelForDeleteAndDraw(uint16_t startPixel);
        void deletePixel();
        void drawPixel();

    public:
        Indicator(uint16_t* CirclePointX, uint16_t* CirclePointY, uint16_t CircleSize, uint16_t SizeOfSector);
        void newSector(uint16_t newStart);
};

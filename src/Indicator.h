#pragma once
#include <Arduino.h>
#include <Adafruit_ST7789.h>

class Indicator
{
    private:
        int const circleSize;
        int* circlePointX;
        int* circlePointY;
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

    public:
        Indicator(Adafruit_ST7789* Screen, int* CirclePointX, int* CirclePointY, int const CircleSize, int SizeOfSector);

        void newSector(uint16_t newStart);
};

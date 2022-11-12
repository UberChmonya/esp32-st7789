
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include "Indicator.h"
#include "circleMassive.h"
#define ST7789_DRIVER // Configure all registers

#define TFT_WIDTH 240
#define TFT_HEIGHT 280
#define SPI_FREQUENCY 40000000
#define SPI_READ_FREQUENCY 20000000
#define SPI_TOUCH_FREQUENCY 2500000

#define TFT_CS 15 // define chip select pin
#define TFT_DC 5  // define data/command pin
#define TFT_RST 4
#define TFT_MOSI 13 // Data out
#define TFT_SCLK 14 // Clock out

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

Indicator indecator = Indicator(circlePointX1, circlePointY1, circleSize1, 30u);

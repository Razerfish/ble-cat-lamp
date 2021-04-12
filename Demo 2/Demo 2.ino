/*
 Name:		Demo_2.ino
 Created:	4/11/2021 7:25:53 PM
 Author:	Fiona College
*/

#include <Adafruit_NeoPixel.h>

#include "lighting.h"

#define LED_PIN 6
#define LED_COUNT 7
#define BRIGHTNESS 255
#define LENGTH 600

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRBW + NEO_KHZ800);

void setup()
{
	Serial.begin(115200);
	strip.begin();
	strip.show();
	strip.setBrightness(255);
}

uint32_t last;

uint16_t i = 0;

uint8_t b;

bool doRainbow = true;


void loop()
{
	if (millis() - last >= 1000 / 60)
	{
		if (doRainbow)
		{
			if (i > LENGTH)
			{
				i = 0;
			}

			strip.fill(rainbowGradient(i, LENGTH, 255));
			strip.show();

			i++;
		}
		else
		{
			// Brightness demonstration
			switch (i)
			{
			case 0:
				strip.fill(colorDimmable(255, 0, 0, 0, b));
				strip.show();
				break;
			case 1:
				strip.fill(colorDimmable(0, 255, 0, 0, b));
				strip.show();
				break;
			case 2:
				strip.fill(colorDimmable(0, 0, 255, 0, b));
				strip.show();
				break;
			case 3:
				strip.fill(colorDimmable(255, 255, 255, 0, b));
				strip.show();
				break;
			//case 4:
				//strip.fill(colorDimmable(0, 0, 0, 255, b));
				//strip.show();
				//break;
			default:
				i = 0;
			}

			b--;
			if (b <= 0)
			{
				b = 255;
				i++;
			}
		}
		

		last = millis();
	}
}

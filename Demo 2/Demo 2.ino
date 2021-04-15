/*
 Name:		Demo_2.ino
 Created:	4/11/2021 7:25:53 PM
 Author:	Fiona College
*/

#include <Adafruit_NeoPixel.h>

#include "lighting.h"

#define LED_PIN 6
#define LED_COUNT 7

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRBW + NEO_KHZ800);

void setup()
{
	Serial.begin(115200);
	Serial.setTimeout(50);

	strip.begin();
	strip.show();
	strip.setBrightness(255);
}


uint8_t brightness = 255;
uint16_t length;
uint16_t pos;
uint32_t last = 0;

char c;

bool rainbowActive = false;


void loop()
{
	if (Serial.available())
	{
		uint8_t buf[3];

		c = Serial.read();

		switch (c)
		{
		case 'C':
			for (int i = 0; i < 3; i++)
			{
				buf[i] = Serial.parseInt();
			}
			strip.fill(colorDimmable(buf[0], buf[1], buf[2], 0, brightness));
			strip.show();
			Serial.println("Set strip to: " + String(buf[0]) + ", " + String(buf[1]) + ", " + String(buf[2]));
			rainbowActive = false;
			break;

		case 'B':
			buf[0] = Serial.parseInt();
			strip.fill(colorDimmable(strip.getPixelColor(0), buf[0]));
			strip.show();
			brightness = buf[0];
			Serial.println("Set brightness to: " + String(buf[0]));
			break;

		case 'W':
			strip.fill(colorDimmable(0, 0, 0, 255, brightness));
			strip.show();
			Serial.println("Set strip to warm white");
			rainbowActive = false;
			break;

		case 'R':
			length = Serial.parseInt();
			rainbowActive = true;
			pos = 0;
			Serial.println("Started rainbow with animation length: " + String(length));
			break;

		default:
			Serial.println("Unknown command: " + String(c));
			break;
		}
	}

	if (rainbowActive && millis() - last >= 1000 / 60)
	{
		if (pos > length)
		{
			pos = 0;
		}

		strip.fill(rainbowGradient(pos, length, brightness));
		strip.show();

		pos++;
		last = millis();
	}
}

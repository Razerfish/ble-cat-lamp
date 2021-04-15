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

/*
uint32_t last;

uint16_t pos = 0;

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
			case 4:
				strip.fill(colorDimmable(0, 0, 0, 255, b));
				strip.show();
				break;
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
*/

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


/*
void loop()
{
	if (Serial.available())
	{
		c = Serial.read();

		if (c != '!')
		{
			Serial.println(F("Invalid command"));
		}
		else
		{
			c = Serial.read();

			switch (c)
			{
			case 'C':
				uint8_t cBuf[3];
				if (Serial.readBytes(cBuf, 3) != 3)
				{
					Serial.println("Malformed request");
				}
				else
				{
					strip.fill(colorDimmable(cBuf[0], cBuf[1], cBuf[2], 0, brightness));
					strip.show();
					Serial.println("Set color: " + String(cBuf[0]) + ", " + String(cBuf[1]) + ", " + String(cBuf[3]));
				}

				rainbowActive = false;

				break;

			case 'B':
				uint32_t current;

				if (Serial.peek() < 0)
				{
					Serial.println("Malformed request");
				}
				else
				{
					brightness = Serial.read();
					current = strip.getPixelColor(0);
					strip.fill(colorDimmable(current, brightness));
					strip.show();
					Serial.println("Set brightness to: " + String(brightness));
				}
				break;

			case 'R':
				uint8_t lBuf[2];

				if (Serial.readBytes(lBuf, 2) != 2)
				{
					Serial.println("Malformed request");
				}
				else
				{
					length = uint16_t(lBuf[0]) << 8 | uint16_t(lBuf[1]);
					rainbowActive = true;
					pos = 0;
				}
				break;

			default:
				Serial.println("Unknown command: " + c);
				break;
			}
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
*/

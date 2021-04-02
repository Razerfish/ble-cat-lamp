// lighting.h

#ifndef _lighting_h
#define _lighting_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <Adafruit_NeoPixel.h>

class CatLamp_NeoPixel : public Adafruit_NeoPixel
{
	using Adafruit_NeoPixel::Adafruit_NeoPixel;

public:
	void rainbowGradientFill(uint16_t pos, uint16_t length, uint8_t brightness = 255);

	static uint32_t ColorDimmable(uint8_t r, uint8_t g, uint8_t b, uint8_t brightness);
	static uint32_t ColorDimmable(uint8_t r, uint8_t g, uint8_t b, uint8_t w, uint8_t brightness);
};

#endif


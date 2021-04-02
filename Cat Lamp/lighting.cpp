// 
// 
// 

#include "lighting.h"

void CatLamp_NeoPixel::rainbowGradientFill(uint16_t pos, uint16_t length, uint8_t brightness)
{
	float ratio = pos / length;

	int normalized = ratio * 256 * 6;

	int range = normalized % 256;

	uint8_t r, g, b;

	switch (normalized / 256)
	{
	case 0: // Red -> Yellow
		r = 255;
		g = range;
		b = 0;
		break;
	case 1: // Yellow -> Green
		r = 255 - range;
		g = 255;
		b = 0;
		break;
	case 2: // Green -> Cyan
		r = 0;
		g = 255;
		b = range;
		break;
	case 3: // Cyan -> Blue
		r = 0;
		g = 255 - range;
		b = 255;
		break;
	case 4: // Blue -> Magenta
		r = range;
		g = 0;
		b = 255;
		break;
	case 5: // Magenta -> Red
		r = 255;
		g = 0;
		b = 255 - range;
		break;
	}

	// Check if we're an RGB or RGBW strip and call fill.
	if (bOffset == rOffset) // RGB
	{
		fill(ColorDimmable(r, g, b, brightness));
	}
	else // RGBW
	{
		fill(ColorDimmable(r, g, b, 0, brightness));
	}

	// Up to the user to call show();
}


uint32_t CatLamp_NeoPixel::ColorDimmable(uint8_t r, uint8_t g, uint8_t b, uint8_t brightness)
{
	float ratio = brightness / 255.0f;

	r *= ratio;
	g *= ratio;
	b *= ratio;

	return ((uint32_t)r << 16) | ((uint32_t)g << 8) | b;
}


uint32_t CatLamp_NeoPixel::ColorDimmable(uint8_t r, uint8_t g, uint8_t b, uint8_t w, uint8_t brightness)
{
	float ratio = brightness / 255.0f;

	r *= ratio;
	g *= ratio;
	b *= ratio;
	w *= ratio;

	return ((uint32_t)w << 24) | ((uint32_t)r << 16) | ((uint32_t)g << 8) | b;
}

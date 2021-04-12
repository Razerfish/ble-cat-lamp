// testData.h

#ifndef _LIGHTINGTEST_H
#define _LIGHTINGTEST_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#define RAINBOW_GRADIENT_LENGTH 1536
#define RAINBOW_REF_LENGTH 24
#define RAINBOW_TEST_INCREMENT 64

#define BRIGHTNESS_REF_LENGTH 30
#define BRIGHTNESS_COLORS 5
#define BRIGHTNESS_TEST_LEVELS 6

const uint32_t rainbowRef[RAINBOW_REF_LENGTH] =
{
	16711680,
	16728064,
	16744448,
	16760832,
	16776960,
	12582656,
	8388352,
	4194048,
	65280,
	65344,
	65408,
	65472,
	65535,
	49151,
	32767,
	16383,
	255,
	4194559,
	8388863,
	12583167,
	16711935,
	16711871,
	16711807,
	16711743
};


const uint32_t brightnessRef[BRIGHTNESS_REF_LENGTH] =
{
	12582912,
	10944512,
	8388608,
	5505024,
	4194304,
	0,
	49152,
	42752,
	32768,
	21504,
	16384,
	0,
	192,
	167,
	128,
	84,
	64,
	0,
	12632256,
	10987431,
	8421504,
	5526612,
	4210752,
	0,
	3221225472,
	2801795072,
	2147483648,
	1409286144,
	1073741824,
	0
};


const uint8_t brightnessLevels[BRIGHTNESS_TEST_LEVELS] =
{
	192,
	167,
	128,
	84,
	64,
	0
};


const uint8_t brightnessColors[BRIGHTNESS_COLORS][4] =
{
	{255, 0, 0, 0},
	{0, 255, 0, 0},
	{0, 0, 255, 0},
	{255, 255, 255, 0},
	{0, 0, 0, 255}
};


#endif

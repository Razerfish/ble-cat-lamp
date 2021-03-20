/*
 Name:		AUnit_Tests.ino
 Created:	3/18/2021 4:37:03 PM
 Author:	fiona.wilson
*/

#include <AUnitVerbose.h>

// Include files to test here.


// Define tests here.

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(115200);
}

// the loop function runs over and over again until power down or reset
void loop() {
	aunit::TestRunner::run();
}

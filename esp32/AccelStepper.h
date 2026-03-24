#pragma once
#include "Arduino.h"
#define AccelStepper_DRIVER 1
#define AccelStepper_FULL2WIRE 2
#define AccelStepper_FULL4WIRE 4
class AccelStepper { public: AccelStepper(uint8_t interface = AccelStepper_FULL4WIRE, uint8_t pin1 = 2, uint8_t pin2 = 3, uint8_t pin3 = 4, uint8_t pin4 = 5) { (void)interface;(void)pin1;(void)pin2;(void)pin3;(void)pin4; } void setMaxSpeed(float speed) { (void)speed; } void setAcceleration(float accel) { (void)accel; } void setSpeed(float speed) { (void)speed; } void moveTo(long absolute) { (void)absolute; } void move(long relative) { (void)relative; } bool run() { return false; } bool runSpeed() { return false; } void runToPosition() {} long distanceToGo() { return 0; } long currentPosition() { return 0; } void setCurrentPosition(long pos) { (void)pos; } void stop() {} };

#include "fanControl.h"

FanControl::FanControl(byte pin)
	:
	control(pin)
{
}
void FanControl::init()
{
	pinMode(control, OUTPUT);
	//control = LOW;
}
void FanControl::start()
{
	digitalWrite(control, HIGH);
}
void FanControl::stop()
{
	digitalWrite(control, LOW);
}
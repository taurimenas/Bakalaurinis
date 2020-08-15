#pragma once
#include <Arduino.h>
class FanControl
{
public:
	FanControl(byte pin);
	void init();
	void start();
	void stop();
private:
	int control;
	//bool state;
};



#pragma once
#include <Arduino.h>


class Time
{
public:
	Time();
	void Start(int page);
	void Stop();
	String GetTime();
	bool timer(int timerDelay);
	void DigitalClockDisplay(int page);
	void printDigits(int digits);
	int GetMins();
	int GetHours();

private:
	int h, m, s;
	unsigned long timerTime;
	unsigned long startTime;
	unsigned long endTime;
	unsigned long timerEndTime = 0;
	bool state = true;
};


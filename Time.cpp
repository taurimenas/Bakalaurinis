#include "Time.h"

Time::Time()
{
	Time::startTime = 0;
	Time::endTime = 0;
}

void Time::Start(int page)
{
	if (page != 1)
	{
		state = true;
	}
	if ((page = 1) && (state == true))
	{
		startTime = millis();
		state = false;
	}
}

void Time::Stop()
{
	Time::endTime = millis();
}

String Time::GetTime()
{
	if (startTime == 0 && endTime == 0)
	{
		return "a";
	}
	unsigned long elapsedTime = endTime - startTime;
	float elapsedTimef = (float)(elapsedTime / 1000);
	String timeStr = String(elapsedTimef);
	return timeStr;
}

bool Time::timer(int timerDelay)
{
//	timerTime = millis();
//	if (timerTime - timerEndTime >= timerDelay)
//	{
//		timerEndTime = timerTime;
//		state = false;
//		return state;
//	}
}

void Time::DigitalClockDisplay(int page)
{
	if (page == 1)
	{
		s = (millis() / 1000) - (startTime / 1000); //-startTime;
		m = s / 60;
		h = s / 3600;
		s = s - m * 60;
		m = m - h * 60;
		Serial.print(h);
		Time::printDigits(m);
		Time::printDigits(s);
		Serial.println("||");
	}
}

void Time::printDigits(int digits)
{
	Serial.print(":");
	if (digits < 10)
	Serial.print('0');
	Serial.print(digits);
}
int Time::GetMins()
{
	return m;
}
int Time::GetHours()
{
	return h;
}

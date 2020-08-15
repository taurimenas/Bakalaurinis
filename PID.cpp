#include "PID.h"

PID::PID(int in_controlPin, int in_sensorPin, double in_Kp, double in_Ki, double in_Kd)
	:
	controlPin(in_controlPin),
	sensorPin(in_sensorPin),
	Kp(in_Kp),
	Ki(in_Ki),
	Kd(in_Kd)
{
	time = millis();
}

int PID::SetTemperature(int page, int desiredTemperature, bool state)
{
	if ((page != 1) && (state == true))
	{
		desiredTemp = 0;
		controlOut = 0;
		state = false;
	}
	if (page == 1)
	{
		pinMode(controlPin, OUTPUT);
		pinMode(sensorPin, INPUT);
		desiredTemp = desiredTemperature;
		return desiredTemp;
	}
}

void PID::CalcOutSignal(int page)
{
	if (page == 1)
	{
		tempIn = CalcTemp();
		error = desiredTemp - tempIn;
		pOutput = error * Kp;
		if (-2 <= error <= 2)
		{
			iOutput = iOutput + (Ki * error);
		}
		previousTime = time;
		time = millis();
		elapsedTime = (time - previousTime) / 1000;
		dOutput = Kd * ((error - previousError) / elapsedTime);
		controlOut = pOutput + iOutput + dOutput;
		if (controlOut < 0)
		{
			controlOut = 0;
		}
		if (controlOut > 1)
		{
			controlOut = 255;
		}

		analogWrite(controlPin, controlOut);
		previousError = error;
	}
	if (page != 1 || desiredTemp == 0)
	{
		analogWrite(controlPin, controlOut);
	}
}

double PID::CalcTemp()
{
	float R1 = 10000;
	float logR2, R2, T, Tc, Tf;
	const float c1 = 1.009249522e-03;
	const float c2 = 2.378405444e-04;
	const float c3 = 2.019202697e-07;

	int vOut = analogRead(sensorPin);
	R2 = R1 * (1023.0 / (float)vOut - 1.0);
	logR2 = log(R2);
	T = (1.0 / (c1 + c2 * logR2 + c3 * logR2 * logR2 * logR2));
	return (double)(T - 273.15);
}

void PID::SerialPrintTemp()
{
	Time t;
	//	Serial.print("setT:");
	//	Serial.print(desiredTemp);
	//	Serial.print("  sensT:");
	//	Serial.print(tempIn);
	//	Serial.print("  OUT:");
	//	Serial.println(controlOut);
	//t.timer(2000, false);
	String desiredTempStr = String(desiredTemp);
	String controlOutStr = String(controlOut);
	String tempInStr = String(tempIn);
	Serial.println(tempInStr + "~" + controlOutStr + "~" + desiredTempStr);
}

int PID::GetTemperature()
{
	delay(500);
	return tempIn;
}

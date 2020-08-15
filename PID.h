#pragma once
#include "Arduino.h"
#include "Time.h"
class PID
{
public:
	PID(int in_controlPin, int in_sensorPin, double Kp, double Ki, double Kd);
	int SetTemperature(int page, int desiredTemperature, bool state);
	double CalcTemp();
	void SerialPrintTemp();
	int GetTemperature();
	void CalcOutSignal(int page);

private:
	int desiredTemp = 0, tempIn, controlOut;
	//int lastDesiredTemp = 0;
	double Kp, Ki, Kd;
	int controlPin;
	int sensorPin;

	//PID skaiciavimams
	float error = 0;
	float previousError;
	int pOutput = 0;
	int iOutput = 0;
	int dOutput = 0;
	float elapsedTime, time, previousTime;
};

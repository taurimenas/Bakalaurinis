#include "fanControl.h"
#include "PID.h"
#include "Button.h"
#include "Lcd.h"
#include "Db.h"
#include "SimpleTimer.h"
#include "Eprom.h"

Lcd lcd(12, 11, 5, 4, 3, 2);
Button btnEnt(6);
PID tempRegulator(9, A4, 40, 0.1, 5);//90.0, 30.0, 80.0);
bool state = true;
Time time;
SimpleTimer timer;
FanControl fanControl(8);
Eprom eprom;
Db list;
bool x = false;
void DigitalClockDisplay()
{
	time.DigitalClockDisplay(btnEnt.PageTracker(lcd.GetIndex()));
}
void setup()
{	
	Serial.begin(9600);
	fanControl.init();
	btnEnt.Init();
	lcd.DisplayPage("     HEATBED", " CONTROL SYSTEM");
	//delay(3000);
	lcd.DisplayPage("ShortClck->ENTER", "LongClck->CANCEL");
	//delay(3000);
	lcd.Clear(1);
	//timer.setInterval(1000, DigitalClockDisplay);
	eprom.Init();
	eprom.SaveTemp();
}

void loop()
{	
	//time.Start(btnEnt.PageTracker(lcd.GetIndex()));
	lcd.Clear(btnEnt.PageTracker(lcd.GetIndex()));
	if (btnEnt.PageTracker(lcd.GetIndex()) == 0)
	{
		lcd.DisplayMaterialList();
		fanControl.stop();
	}
	if (btnEnt.PageTracker(lcd.GetIndex()) == 1)
	{	
		fanControl.start();
		tempRegulator.SerialPrintTemp();
		//time.DigitalClockDisplay(btnEnt.PageTracker(lcd.GetIndex()));
		int T1 = list.GetTempByIndex(lcd.GetIndex());
		int T2 = tempRegulator.GetTemperature();
		String M = list.GetMaterialByIndex(lcd.GetIndex());
		int min = time.GetMins();
		int h = time.GetHours();
		lcd.DisplayPrintingWindow("Printing..",(String)h, (String)min, M,T1,T2);
	}	
	if (btnEnt.PageTracker(lcd.GetIndex()) == 2)
	{
		if (!x)
		{
			x = lcd.DisplayAddText(2);
			lcd.GetText();
		}
		if (x)
		{
			lcd.DisplayAddNums(3);
			lcd.GetTemp();
		}
	}
	tempRegulator.SetTemperature(btnEnt.PageTracker(lcd.GetIndex()), list.GetTempByIndex(lcd.GetIndex()), true);
	tempRegulator.CalcOutSignal(btnEnt.PageTracker(lcd.GetIndex()));

}

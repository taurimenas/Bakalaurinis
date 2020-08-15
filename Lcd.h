#pragma once
#include <Arduino.h>
#include <LiquidCrystal.h>
#include "Button.h"
#include "Db.h"
#include <string.h>
class Lcd
{
public:
	//Eeprom Eeprom;
	Lcd(const byte rs, const byte en, const byte d4, const byte d5, const byte d6, const byte d7);
	void DisplayMaterialList();
	bool DisplayAddText(int page);
	void DisplayAddNums(int page);
	String GetText();
	String GetTemp();
	void PrintingWindow(int page);
	void DisplayPage(String fLine, String sLine = "");
	void DisplayPrintingWindow(String Txt, String timeHour, String timeMin, String Material, int Temp1, int Temp2);
	void Display4var(String fLine, String sLine);
	int GetIndex();
	void Clear(int page);
	void EnterText(const String title);
	
private:
	LiquidCrystal lcd;
	Button btnForward;
	Button btnBackward;
	Button btnEnter;
	static constexpr int size = 40;
	char ABC[size] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q' ,'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8','9', '_',' ', ' ', ' ' };
	char number[11] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ' '};
	int index;
	int lastPage;
	bool clearState;
	unsigned long endTime;
	int poss;
	String newTemp;
	String newMaterial;
	bool save;
	char m[8];
	char t[2];
	Db list;
};


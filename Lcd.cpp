#include "Lcd.h"

Lcd::Lcd(const byte rs, const byte en, const byte d4, const byte d5, const byte d6, const byte d7)
	:
	lcd(rs, en, d4, d5, d6, d7),
	btnForward(10),
	btnBackward(7),
	btnEnter(6)
{
	lcd.begin(16, 2);
	btnForward.Init();
	btnBackward.Init();
	index = 0;
	endTime = 0;
	clearState = 0;
	poss = 0;
	save = false;
}

void Lcd::DisplayMaterialList()
{
	Db Db;
	if (clearState == true)
	{
		unsigned long startTime = millis();

		if (startTime - endTime >= 3000)
		{
			endTime = startTime;
			DisplayPage("Press up or down", "to continue");
			clearState = false;
		}
	}
	if (btnForward.ShortClickListener())
	{
		if (index == (Db.GetListLenght() - 1))
		{
			index = -1;
		}
		index++;
		lcd.clear();
		DisplayPage(Db.GetMaterialByIndex(index), (String)Db.GetTempByIndex(index));
	}
	if (btnBackward.ShortClickListener())
	{
		if (index == 0)
		{
			index = Db.GetListLenght();
		}
		index--;
		lcd.clear();
		DisplayPage(Db.GetMaterialByIndex(index), (String)Db.GetTempByIndex(index));
	}
}

bool Lcd::DisplayAddText(int page)
{
	if (page == 2)
	{
		lcd.setCursor(poss, 1);
		lcd.print(ABC[index]);
		if (btnForward.ShortClickListener())
		{
			if (index < size - 1)
			{
				index++;
			}
			else
			{
				index = 0;
			}
		}
		if (btnBackward.ShortClickListener())
		{
			if (index > 0)
			{
				index--;
			}
			else
			{
				index = size - 1;
			}
		}
		if (clearState == 1)
		{
			lcd.clear();
			lcd.setCursor(0, 0);
			lcd.print("Material name");
			poss = 0;
			clearState = 0;
		}
		if (ABC[index] == ' ' && btnEnter.ShortClickListener())
		{
			lcd.setCursor(0, 0);
			lcd.print("Material saved");
			delay(2000);
			newMaterial = String(m);
			//Serial.println(newMaterial);
			save = true;
			clearState = 1;	
			return true;
		}
		if ((poss == 8) && btnEnter.ShortClickListener())
		{
			lcd.setCursor(0, 0);
			lcd.print("Material saved");
			delay(2000);
			newMaterial = String(m);
			clearState = 1;
			return true;
		}
		if (btnEnter.ShortClickListener())
		{
			if (poss < 8)
			{
				lcd.setCursor(poss, 1);
				lcd.print(ABC[index]);
				m[poss] = ABC[index];
				poss++;
			}
			else
			{
				poss = 0;
			}
		}
	}
	return false;
}

void Lcd::DisplayAddNums(int page)
{
	if (page == 3)
	{
		lcd.setCursor(poss, 1);
		lcd.print(number[index]);
		if (btnForward.ShortClickListener())
		{
			if (index < 10)
			{
				index++;
			}
			else
			{
				index = 0;
			}
		}
		if (btnBackward.ShortClickListener())
		{
			if (index > 0)
			{
				index--;
			}
			else
			{
				index = 10;
			}
		}
		if (clearState == 1)
		{
			lcd.clear();
			lcd.setCursor(0, 0);
			lcd.print("Set temp");
			poss = 0;
			clearState = 0;
		}
		if (number[index] == ' ' && btnEnter.ShortClickListener())
		{
			lcd.setCursor(0, 0);
			lcd.print("Temp saved");
			delay(2000);
			newTemp = String(t);
			//Serial.println(newMaterial);
			save = true;
			clearState = 1;
		}
		if ((poss == 8) && btnEnter.ShortClickListener())
		{
			lcd.setCursor(0, 0);
			lcd.print("Temp saved");
			delay(2000);
			newTemp = String(t);
			clearState = 1;
		}
		if (btnEnter.ShortClickListener())
		{
			if (poss < 8)
			{
				lcd.setCursor(poss, 1);
				lcd.print(number[index]);
				t[poss] = number[index];
				poss++;
			}
			else
			{
				poss = 0;
			}
		}
	}
}
String Lcd::GetText()
{
	if (save)
	{
		save = !save;
		Serial.println("Material saved");
		//Serial.println(newMaterial);
		lcd.clear();
		return newMaterial;
	}
}
String Lcd::GetTemp()
{
	if (save)
	{
		save = !save;
		Serial.println("Temp saved");
		//Serial.println(newMaterial);
		lcd.clear();
		return newTemp;
	}
}
void Lcd::DisplayPage(String fLine, String sLine)
{
	lcd.setCursor(0, 0);
	lcd.print(fLine);
	lcd.setCursor(0, 1);
	lcd.print(sLine);
}

void Lcd::DisplayPrintingWindow(String Txt, String timeHour, String timeMin, String Material, int Temp1, int Temp2)
{
	lcd.setCursor(0, 0);
	lcd.print(Txt);
	lcd.setCursor(12, 0);
	lcd.print(timeHour);
	lcd.setCursor(13, 0);
	lcd.print(":");
	lcd.setCursor(14, 0);
	lcd.print(timeMin);
	lcd.setCursor(0, 1);
	lcd.print(Material);
	lcd.setCursor(Material.length() + 1, 1);
	lcd.print(Temp1);
	lcd.setCursor(13, 1);
	lcd.print("-");
	lcd.setCursor(13, 1);
	lcd.print(Temp2);
}

int Lcd::GetIndex()
{
	return index;
}

void Lcd::Clear(int page)
{
	if (page != lastPage)
	{
		lcd.clear();
		lastPage = page;
		clearState = true;
	}
}

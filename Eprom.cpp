#include "Eprom.h"

Eprom::Eprom()
{
	
}


void Eprom::Init()
{
//	eeAddress = 0;
//	saveState = false;
//	index = 0;
//
//	int i = 0;
//	for (; i < maxLenght; i++)
//	{
//		if (materials[i] == "")
//		{
//			break;
//		}
//	}
//	
//	for (index = 1; index <= i; index++)
//	{
//		temps[index] = EEPROM.get(eeAddress, f[index]);
//		eeAddress += sizeof(f[index]);
//		Serial.println(temps[index]);
//	}
}

int Eprom::SaveTemp()
{
//	int i = 0;
//	int x[20];
//	for (index = 1; index < maxLenght; index++)
//	{
//		x[index] = data.GetTempByIndex(index);
//		if (x[index] > 0)
//		{
//			i++;
//		}
//	}
//	for (index = 1; index <= i; index++)
//	{
//		f[index] = data.GetTempByIndex(index);
//		EEPROM.put(eeAddress, f[index]);
//		eeAddress += sizeof(f[index]);
//		temps[index] = EEPROM.get(eeAddress - sizeof(f[index]), f[index]);
//		Serial.println(temps[index]);
//	}
//	for (index = 1; index <= i; index++)
//	{
//		g[index] = data.GetMaterialByIndex(index);
//		EEPROM.put(eeAddress, g[index]);
//		eeAddress += sizeof(g[index]);
//		materials[index] = EEPROM.get(eeAddress - sizeof(g[index]), g[index]);
//		Serial.println(materials[index]);
//	}
}

String Eprom::GetMaterial(int index)
{
//	return materials[index];
}

int Eprom::GetTemp(int index)
{
//	return temps[index];
}

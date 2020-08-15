#pragma once

#include <EEPROM.h>
#include "Db.h"

class Eprom
{
public:
	
	Eprom();
	void Init();
	int SaveTemp();
	String GetMaterial(int index);
	int GetTemp(int index);
	
private:
	String names[7];
	String temp[3];
	int f[20];
	//String g[20];
	int index;
	int eeAddress;
	bool saveState;
	static constexpr int maxLenght = 20;
	//String materials[maxLenght];
	int temps[maxLenght];
	String x[5];
	//Db data;
};

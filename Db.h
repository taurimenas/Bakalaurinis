#pragma once
#include "Arduino.h"

class Db
{
public:
	Db();
	void Init();
	int GetMaxListLenght() const;
	int GetListLenght() const;
	String GetMaterialByTemp(int temp) const;
	int GetTempByMaterial(String material) const;
	String GetMaterialByIndex(int index) const;
	int GetTempByIndex(int index) const;
	String GetMaterial(int index) const;
private:
	int saveState = 0;
	static constexpr int maxLenght = 8;
	String materials[maxLenght] = { "ADD MATERIAL", "PLA", "ABS", "test" };//"ADD MATERIAL", "PLA", "ABS", "NYLON", "TPE"};
	int temps[maxLenght] = { 0, 60, 110, 40 };//0, 60, 65, 70, 75 };
};

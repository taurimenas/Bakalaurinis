#include "Db.h"

Db::Db()
{
	//cia reikia paimti duomenis is andriaus atminties
}

void Db::Init()
{

}

int Db::GetMaxListLenght() const
{
	return maxLenght;
}

int Db::GetListLenght() const
{
	int i = 0;
	for (; i < maxLenght; i++)
	{
		if (materials[i] == "")
		{
			break;
		}
	}
	return i;
}
String Db::GetMaterialByTemp(int temp) const
{
	for (int i = 0; i < GetListLenght(); i++)
	{
		if (temps[i] == temp)
		{
			return materials[i];
		}
	}
	return "";
}

int Db::GetTempByMaterial(String material) const
{
	for (int i = 0; i < GetListLenght(); i++)
	{
		if (materials[i] == material)
		{
			return temps[i];
		}
	}
	return 0;
}

String Db::GetMaterialByIndex(int index) const
{
	if (index >= GetListLenght()) { return ""; }
	return materials[index];
}

int Db::GetTempByIndex(int index) const
{
	if (index >= GetListLenght()) { return 0; }
	return temps[index];
}

String Db::GetMaterial(int index) const
{
	if (index >= GetListLenght()) { return ""; }
	String material = GetMaterialByIndex(index);
	String temperature = String(GetTempByIndex(index));
	return material + " " + temperature;
}
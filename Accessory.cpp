#include "pch.h"
#include "Accessory.h"

Accessory::Accessory(string bodyPart, long productCode, string brand, string type, int stock, int shelf, float price)
	: Product(productCode, brand, type, color, stock, shelf, price)
{
	this->bodyPart = bodyPart;
}

string Accessory::getBodyPart()
{
	return bodyPart;
}

void Accessory::showInfo()
{
	Product::showInfo();
	Console::showAccessory(bodyPart);
}

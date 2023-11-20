#include "pch.h"
#include "Accessory.h"

Accessory::Accessory(string bodyPart, long productCode, string brand, string description, string type, int stock, int shelf, float price)
	: Product(productCode, brand, description, type, color, stock, shelf, price)
{
	this->bodyPart = bodyPart;
}

string Accessory::getBodyPart()
{
	return bodyPart;
}
#include "pch.h"
#include "Clothing.h"

Clothing::Clothing(vector <int> clothingSize, string garment, long productCode, string brand, string type, string color, int stock, int shelf, float price)
	: Product(productCode, brand, type, color, stock, shelf, price)
{
	this->clothingSize = clothingSize;
	this->garment = garment;
}

vector<int> Clothing::getClothingSize()
{
	return clothingSize;
}

string Clothing::getGarment()
{
	return garment;
}

void Clothing::showInfo()
{
	Product::showInfo();
	Console::showSizes();
	for (int size : clothingSize)
	{
		Console::printSizes(size);
	}
	Console::printEndline();
}

bool Clothing::operator<=(Clothing& c)
{
	return this->getProductCode() <= c.getProductCode();
}

bool Clothing::operator>=(Clothing& c)
{
	return this->getProductCode() >= c.getProductCode();
}
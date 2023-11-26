#include "pch.h"
#include "Shoe.h"

Shoe::Shoe(vector <int> shoeSize, long productCode, string brand, string type, int stock, int shelf, float price)
	: Product(productCode, brand, type, color, stock, shelf, price)
{
	this->shoeSize = shoeSize;
}
vector<int> Shoe::getShoeSize()
{
	return shoeSize;
}
void Shoe::showInfo()
{
	Product::showInfo();
	Console::showSizes();
	for (int size : shoeSize)
	{
		Console::printSizes(size);
	}
	Console::printEndline();
}

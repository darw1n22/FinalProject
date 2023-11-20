#include "pch.h"
#include "Clothing.h"

Clothing::Clothing(vector <int> clothingSize, string garment, long productCode, string brand, string description, string type, int stock, int shelf, float price)
	: Product(productCode, brand, color, description, type, stock, shelf, price)
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
	cout << "available sizes: ";
	for (int size : clothingSize)
	{
		cout << size << " ";
	}
	cout << endl;
}
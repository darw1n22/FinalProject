#include "pch.h"
#include "Shoe.h"

Shoe::Shoe(vector <int> shoeSize, bool hasVelcro, long productCode, string brand, string description, string type, int stock, int shelf, float price)
	: Product(productCode, brand, description, type, color, stock, shelf, price)
{
	this->shoeSize = shoeSize;
	this->hasVelcro = hasVelcro;
}
vector<int> Shoe::getShoeSize()
{
	return shoeSize;
}
bool Shoe::getHasVelcro()
{
	return hasVelcro;
}

void Shoe::showInfo()
{
	Product::showInfo();
	cout << "available sizes: ";
	for (int size : shoeSize)
	{
		cout << size << " ";
	}
	cout << endl;
	if (hasVelcro)
	{
		cout << "The shoe has velcro" << endl;
	}
	else {
		cout << "the shoe has laces" << endl;
	}
}

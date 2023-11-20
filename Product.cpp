#include "pch.h"
#include "Product.h"

Product::Product(long productCode, string brand, string description, string type, string color, int stock, int shelf, float price)
{
	this->productCode = productCode;
	this->brand = brand;
	this->description = description;
	this->type = type;
	this->stock = stock;
	this->shelf = shelf;
	this->price = price;
	this->color = color;

}
Product::~Product()
{
}

int Product::getStock()
{
	return stock;
}

void Product::setStock(int newStock)
{
	stock = newStock;
}

long Product::getProductCode()
{
	return productCode;
}

string Product::getBrand()
{
	return brand;
}

void Product::setBrand(string newBrand)
{
	brand = newBrand;
}
string Product::getType()
{
	return type;
}
string Product::getDescription()
{
	return description;
}
float Product::getPrice()
{
	return price;
}

void Product::showInfo()
{
	cout << "Product code: " << productCode << endl;
	cout << "Brand: " << brand << endl;
	cout << "Description: " << description << endl;
	cout << "Color: " << color << endl;
	cout << "Type: " << type << endl;
	cout << "Stock: " << stock << " unities" << endl;
	cout << "It is on shelf number " << shelf << endl;
	cout << "Price: " << price << endl;
}
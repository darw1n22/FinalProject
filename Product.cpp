#include "pch.h"
#include "Product.h"

Product::Product(long productCode, string brand, string type, string color, int stock, int shelf, float price)
{
	this->productCode = productCode;
	this->brand = brand;
	this->type = type;
	this->color = color;
	this->stock = stock;
	this->shelf = shelf;
	this->price = price;
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
float Product::getPrice()
{
	return price;
}

void Product::setPrice(float newPrice)
{
	price = newPrice;
}

void Product::showInfo()
{
	Console::showProductInformation(productCode, brand, type, color, stock, shelf, price);
}

bool Product::operator<=(Product& p)
{
	return this->productCode <= p.productCode;
}

bool Product::operator>=(Product& p)
{
	return this->productCode >= p.productCode;
}

float Product::getTotalCost()
{
	return price * stock;
}

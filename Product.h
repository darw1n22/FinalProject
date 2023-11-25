#pragma once
#include <iostream>
using namespace std;
class Product
{
private:

public:
	long productCode;
	string brand, type, color;
	int stock, shelf;
	float price;
	Product(long productCode, string brand, string type, string color, int stock, int shelf, float price);
	~Product();
	int getStock();
	void setStock(int newStock);
	long getProductCode();
	string getBrand();
	void setBrand(string newBrand);
	string getType();
	float getPrice();
	void setPrice(float newPrice);
	virtual void showInfo();
};


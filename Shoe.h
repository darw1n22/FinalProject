#pragma once
#include "Product.h"
#include <vector>

class Shoe : public Product
{
private:
	vector <int> shoeSize;
public:
	Shoe(vector <int> shoeSize, long productCode, string brand, string type, string color, int stock, int shelf, float price);

	vector <int> getShoeSize();
	void showInfo();
	bool operator<=(Shoe& s);
	bool operator>=(Shoe& s);
};


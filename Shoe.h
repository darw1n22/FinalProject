#pragma once
#include "Product.h"
#include <vector>

class Shoe : public Product
{
private:
	vector <int> shoeSize;
	bool hasVelcro;
public:
	Shoe(vector <int> shoeSize, bool hasVelcro, long productCode, string brand, string description, string type, int stock, int shelf, float price);

	vector <int> getShoeSize();
	bool getHasVelcro();
};


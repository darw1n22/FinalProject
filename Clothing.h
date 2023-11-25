#pragma once
#include "Product.h"

class Clothing : public Product
{
private:
	vector <int> clothingSize;
	string garment;
public:
	Clothing(vector <int> clothingSize, string garment, long productCode, string brand, string type, int stock, int shelf, float price);

	vector <int> getClothingSize();
	string getGarment();
	void showInfo();
};



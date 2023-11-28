#pragma once
#include "Product.h"

class Clothing : public Product
{
private:
	vector <int> clothingSize;
	string garment;
public:
	Clothing(vector <int> clothingSize, string garment, long productCode, string brand, string type, string color, int stock, int shelf, float price);

	vector <int> getClothingSize();
	string getGarment();
	void showInfo();
	bool operator<=(Clothing& c);
	bool operator>=(Clothing& c);
};



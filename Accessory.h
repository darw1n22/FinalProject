#pragma once
#include "Product.h"

class Accessory : public Product
{
private:
	string bodyPart;
public:
	Accessory(string bodyPart, long productCode, string brand, string type, int stock, int shelf, float price);
	string getBodyPart();
	void showInfo();
};

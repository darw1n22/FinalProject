#pragma once
#include "Product.h"

class Accessory : public Product
{
private:
	string bodyPart;
public:
	Accessory(string bodyPart, long productCode, string brand, string type, string color, int stock, int shelf, float price);
	string getBodyPart();
	void showInfo();
	bool operator<=(Accessory& a);
	bool operator>=(Accessory& a);
};

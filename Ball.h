#pragma once
#include "Product.h"

class Ball : public Product
{
private:
	int weight;
	string sport;
public:
	Ball(int weight, string sport, long productCode, string brand, string type, int stock, int shelf, float price);
	int getWeight();
	string getSport();
	void showInfo();
};


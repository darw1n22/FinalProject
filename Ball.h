#pragma once
#include "Product.h"

class Ball : public Product
{
private:
	int weight;
	string sport;
public:
	Ball(int weight, string sport, long productCode, string brand, string type, string color, int stock, int shelf, float price);
	int getWeight();
	string getSport();
	void showInfo();
	bool operator<=(Ball& b);
	bool operator>=(Ball& b);
};


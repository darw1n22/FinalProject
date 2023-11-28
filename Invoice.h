#pragma once
#include "Client.h"
#include "Staff.h"
#include "Product.h"

class Invoice
{
private:
	Client* clientToBuy;
	Staff* staffToSell;
	vector <Product*> productsSold;
	float amountOfPurchase;
public:
	Invoice(Client* clientToBuy, Staff* StaffToSell, vector<Product*> productsSold, float amountOfPurchase);
	~Invoice();

	void showInvoice();
};


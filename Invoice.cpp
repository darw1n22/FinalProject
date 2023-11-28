#include "pch.h"
#include "Invoice.h"

Invoice::Invoice(Client* clientToBuy, Staff* staffToSell, vector<Product*> productsSold, float amountOfPurchase)
{
	this->clientToBuy = clientToBuy;
	this->staffToSell = staffToSell;
	this->productsSold = productsSold;
	this->amountOfPurchase = amountOfPurchase;
}

Invoice::~Invoice()
{
}

void Invoice::showInvoice()
{
	Console::invoiceDesing(clientToBuy, staffToSell, productsSold, amountOfPurchase);
}
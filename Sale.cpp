#include "pch.h"
#include "Sale.h"

Sale::Sale(long saleId, Client* client, Staff* salesPerson)
{
	this->saleId = saleId;
	this->client = client;
	this->salesPerson = salesPerson;
}

Sale::~Sale()
{
}

long Sale::getSaleId()
{
	return saleId;
}

Client* Sale::getClient()
{
	return client;
}

Staff* Sale::getSalesPerson()
{
	return salesPerson;
}

vector<Product*> Sale::getProducts()
{
	return products;
}

void Sale::addProduct(Product* product)
{
	products.push_back(product);
}

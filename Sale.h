#pragma once
#include "Staff.h"
#include "Client.h"
#include "Product.h"
#include<vector>

class Sale
{
private:
	long saleId;
	Client* client;
	Staff* salesPerson;
	vector<Product*> products;
public:
	Sale(long saleId, Client* client, Staff* salesPerson)
		: saleId(saleId), client(client), salesPerson(salesPerson)
	{}
	~Sale();
	long getSaleId();
	Client* getClient();
	Staff* getSalesPerson();
	vector<Product*> getProducts();
	void addProduct(Product* product);
};

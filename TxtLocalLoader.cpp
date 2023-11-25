#include "pch.h"
#include "TxtLocalLoader.h"

TxtLocalLoader::~TxtLocalLoader() {
}

TxtLocalLoader::TxtLocalLoader() {
}

vector<Client*> TxtLocalLoader::vecClient()
{
	long id, phone;
	int gender, age, purchases, totalPurchases, numPurchases;
	string name, lastName, email, address;
	bool isPremium;
	ifstream archivo("clients.txt");

	vector<Client*> vecClient;

	while (archivo.good()) {
		archivo >> id;
		archivo >> name;
		archivo >> lastName;
		archivo >> gender;
		archivo >> age;
		archivo >> email;
		archivo >> address;
		archivo >> phone;
		archivo >> isPremium;
		archivo >> purchases;
		archivo >> totalPurchases;
		archivo >> numPurchases;
		Client* ptrClient = new Client(id, name, lastName, gender, email, address, phone, age, isPremium, purchases, totalPurchases, numPurchases);
		vecClient.push_back(ptrClient);

	}
	archivo.close();

	return vecClient;
}

vector<Staff*> TxtLocalLoader::vecStaff()
{
	long id, phone;
	string name, lastName, email, address, jobTitle, profession;
	int gender, age, salary, experience, products_sold;
	ifstream archivo("staff.txt");

	vector<Staff*> vecStaff;

	while (archivo.good()) {
		archivo >> id;
		archivo >> name;
		archivo >> lastName;
		archivo >> gender;
		archivo >> age;
		archivo >> email;
		archivo >> address;
		archivo >> phone;
		archivo >> jobTitle;
		archivo >> profession;
		archivo >> salary;
		archivo >> experience;
		archivo >> products_sold;
		Staff* ptrStaff = new Staff(id, name, lastName, gender, email, address, phone, age, jobTitle, profession, salary, experience, products_sold);

		vecStaff.push_back(ptrStaff);

	}
	archivo.close();

	return vecStaff;
}

vector<Owner*> TxtLocalLoader::vecOwner()
{
	long id, phone;
	string name, lastName, email, address;
	int gender, age, budget;
	ifstream archivo("owners.txt");

	vector<Owner*> vecOwner;

	while (archivo.good()) {
		archivo >> id;
		archivo >> name;
		archivo >> lastName;
		archivo >> gender;
		archivo >> age;
		archivo >> email;
		archivo >> address;
		archivo >> phone;
		archivo >> budget;

		Owner* ptrOwner = new Owner(id, name, lastName, gender, email, address, phone, age, budget);

		vecOwner.push_back(ptrOwner);

	}
	archivo.close();

	return vecOwner;
}
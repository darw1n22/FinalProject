#pragma once
#include "Person.h"
#include<iostream>

using namespace std;

class Owner :public Person
{
private:
	int budget = 0;
	//Person* person;
public:
	/*
	Owner(long id, long phone, const string& name, string& lastname, string& email, string& address, int gender, int age, int budget)
		: Person(id, name, lastname, gender, email, address, phone, age), budget(budget) {}
	Owner(int budget) :Person(id, name, lastname, gender, email, address, phone, age), budget(budget) {}
	Owner(Person* Person, int budget) :Person(id, name, lastname, gender, email, address, phone, age), budget(budget) {}
	*/
	Owner(long id, string name, string lastname, int gender, string email, string address, long phone, int age, int budget);
	~Owner();
	int getBudget();
	void setBudget(int newBudget);
	void displayInfo() override {
		Person::displayInfo();
		cout << "Budget: $" << budget << endl;
	}
};


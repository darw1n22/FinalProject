#pragma once
#include<string>
#include<iostream>

using namespace std;

class Person
{
private:

protected:
	long id, phone;
	string name, lastname, email, address;
	int gender, age;
public:
	Person(long id, string name, string lastname, int gender, string email, string address, long phone, int age);
	~Person();
	long getId();
	long getPhone();
	string& getName();
	string& getLastname();
	string& getEmail();
	string& getAddress();
	int getGender();
	int getAge();
	void setId(long newId);
	void setPhone(long newPhone);
	void setName(string& newName);
	void setLastname(string& newLastname);
	void setEmail(string& newEmail);
	void setAddress(string& newAddress);
	void setGender(int newGender);
	void setAge(int newAge);
	virtual void displayInfo();
};
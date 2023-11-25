#include "pch.h"
#include "Person.h"

Person::Person(long id, string name, string lastname, int gender, string email, string address, long phone, int age)
{
	this->id = id;
	this->name = name;
	this->lastname = lastname;
	this->gender = gender;
	this->email = email;
	this->address = address;
	this->phone = phone;
	this->age = age;
}
Person::~Person()
{
}
long Person::getId()
{
	return id;
}
long Person::getPhone()
{
	return phone;
}

string& Person::getName()
{
	return name;
}

string& Person::getLastname()
{
	return lastname;
}

string& Person::getEmail()
{
	return email;
}

string& Person::getAddress()
{
	return address;
}

int Person::getGender()
{
	return gender;
}

int Person::getAge()
{
	return age;
}

void Person::setId(long newId)
{
	id = newId;
}

void Person::setPhone(long newPhone)
{
	phone = newPhone;
}

void Person::setName(string& newName)
{
	name = newName;
}

void Person::setLastname(string& newLastname)
{
	lastname = newLastname;
}

void Person::setEmail(string& newEmail)
{
	email = newEmail;
}

void Person::setAddress(string& newAddress)
{
	address = newAddress;
}

void Person::setGender(int newGender)
{
	gender = newGender;
}

void Person::setAge(int newAge)
{
	age = newAge;
}

void Person::displayInfo()
{
	cout << "ID: " << id << endl;
	cout << "Name: " << name << endl;
	cout << "Lastname: " << lastname << endl;
	cout << "Gender: " << gender << endl;
	cout << "Age: " << age << endl;
	cout << "Email: " << email << endl;
	cout << "Address: " << address << endl;
	cout << "Phone: " << phone << endl;
}
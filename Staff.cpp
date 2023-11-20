#include "pch.h"
#include "Staff.h"

Staff::Staff(long id, string name, string lastname, int gender, string email, string address, long phone, int age, string jobTitle, string profession, int salary, int experience,/* Person* person,*/ int productsSold)
	:Person(id,name,lastname,gender,email,address,phone,age)
{
	this->jobTitle = jobTitle;
	this->profession = profession;
	this->salary = salary;
	this->experience = experience;
	this->productsSold = productsSold;
}
Staff::~Staff()
{
}
string& Staff::getJobTitle()
{
	return jobTitle;
}

void Staff::setJobTitle(string& title)
{
	jobTitle = title;
}

string& Staff::getProfession()
{
	return profession;
}
void Staff::setProfession(string& prof)
{
	profession = prof;
}

int Staff::getSalary()
{
	return salary;
}

void Staff::setSalary(int newSalary)
{
	salary = newSalary;
}

int Staff::getExperience()
{
	return experience;
}

void Staff::setExperience(int exp)
{
	experience = exp;
}

int Staff::getProductsSold()
{
	return productsSold;
}

void Staff::setProductsSold(int newproductsSold)
{
	productsSold = newproductsSold;
}

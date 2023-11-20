#pragma once
#include "Person.h"

class Staff :public Person
{
private:
	string jobTitle, profession;
	int salary, experience;
	//Person* person;
	int productsSold;
public:
	/*
	Staff(long id, long phone, string& name, string& lastname, string& email, string& address, int gender, int age, string& jobTitle, string& profession, int salary, int experience, int productsSold)
		:Person(id, name, lastname, gender, email, address, phone, age), jobTitle(jobTitle), profession(profession), salary(salary), experience(experience), productsSold(productsSold) {}
	Staff(Person* person, string& jobTitle, string& profession, int salary, int experience) :Person(id, name, lastname, gender, email, address, phone, age), jobTitle(jobTitle), profession(profession), salary(salary), experience(experience) {}
	*/
	Staff(long id, string name, string lastname, int gender, string email, string address, long phone, int age, string jobTitle, string profession, int salary, int experience, /*Person* person,*/ int productsSold);
	~Staff();
	string& getJobTitle();
	void setJobTitle(string& title);
	string& getProfession();
	void setProfession(string& prof);
	int getSalary();
	void setSalary(int newSalary);
	int getExperience();
	void setExperience(int exp);
	int getProductsSold();
	void setProductsSold(int newproductsSold);
	void displayInfo() override {
		Person::displayInfo();
		cout << "Job Title: " << jobTitle << endl;
		cout << "Profession: " << profession << endl;
		cout << "Salary: $" << salary << endl;
		cout << "Experience: " << experience << " years" << endl;
		cout << "Number of products sold: " << productsSold << endl;
	}


};


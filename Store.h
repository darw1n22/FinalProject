#pragma once
#include"Person.h"
#include"Client.h"
#include"Owner.h"
#include"Staff.h"
#include"Product.h"
#include"Clothing.h"
#include"Ball.h"
#include"Shoe.h"
#include"Sale.h"
#include"Accessory.h"
#include<vector>
#include<Windows.h>
#include<conio.h>
#include "Console.h"

class Store
{
private:
	Console* console = nullptr;
	vector<Person*> people;
	vector<Staff*> staffs;
	vector<Client*> clients;
	vector<Product*> products;
	Owner* owner = nullptr;
	vector <Clothing*> clothes;
	vector <Shoe*> shoes;
	vector <Ball*> balls;
	vector <Accessory*> accessories;
	void showMenu();
	void addPersonInfo(long& id, long& phone, string& name, string& lastname, string& email, string& address, int& gender, int& age);
	void registerClient();
	void editClientInfo();
	void registerStaff();
	void editStaffInfo();
	void registerOwner();
	void editOwnerInfo();
	void editSalary();
	void EditPersonInfo();
	void showPersonInfo();
	void showClientByType();
	void makePurchase();
	void purchaseMenu();
	void raiseSalaryDependingOnNumberSold();
	void registerAProduct();
	void showProduct();
	void searchAProduct();
	void showFullInventory();
public:
	Store();
	~Store();
	void run();
};


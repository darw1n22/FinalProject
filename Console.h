#pragma once
#include <iostream>

using namespace std;

class Console
{
private:

public:
	static void printEndline();
	static void printSeparator();
	////////////////////////// STORE //////////////////////////
	static void showMainMenu();
	template <typename T> static T readFromKeyboard();
	static void completedProgram();
	static void invalid();
	static void returnToPreviousMenu();
	static void fireEmployee();
	static void numberOfFire();
	static void hireEmployee();
	static void numberOfHire();

	////////////////////////// PRODUCT //////////////////////////
	static void showProductsMenu();
	static void showTitlesOfProducts(string productType);
	static void selectProduct();
	static void searchProducts();
	static void searchProductsMenu();
	static void searchClothing();
	static void searchShoes();
	static void searchBall();
	static void searchAccessories();
	static void enterProductCode();
	static int amountOfProducts();
	static void showProductInformation(long productCode, string brand, string type, string color, int stock, int shelf, float price);
	static void showAccessory(string bodyPart);
	static void showBall(int weight, string sport);
	static void showSizes();
	static void printSizes(int size);
	static void enterTheSize();
	static void enterTheBrand();
	static void enterThePrice();
	static void enterTheColor();
	static void enterTheGarment();
	static void enterTheSport();
	static void enterBodyPart();
	static void enterTheWeight();
	static void readProducts(long &productCode, string &brand, string &sport, int& typeOption, int &stock,int &shelf,float &price);

	////////////////////////// PERSON //////////////////////////
	static void showClientsAndEmployeesMenu();
	static void enterPersonId();

	////////////////////////// SALES //////////////////////////
	static void inactivePromotion();
};


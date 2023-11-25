#pragma once
#include <iostream>

using namespace std;

class Console
{
private:

public:
	////////////////////////// STORE //////////////////////////
	static void showMainMenu();
	static int selectOption();
	static void completedProgram();
	static void invalidSelection();

	////////////////////////// PRODUCT //////////////////////////
	static void showProductsMenu();
	static void showTitlesOfProducts(string productType);

	////////////////////////// PERSON //////////////////////////
};


#pragma once
#include <iostream>

using namespace std;

class Console
{
private:

public:
	void showMainMenu();
	int selectOption();
	void completedProgram();
	void invalidSelection();
	void showProductsMenu();
	void showTitlesOfProducts(string productType);
};


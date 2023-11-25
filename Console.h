#pragma once
#include <iostream>

using namespace std;

class Console
{
private:

public:
	/*
	void showMainMenu();
	int selectOption();
	void completedProgram();
	void invalidSelection();
	void showProductsMenu();
	void showTitlesOfProducts(string productType);
	*/
	virtual void showMainMenu() = 0;
	virtual int selectOption() = 0;
	virtual void completedProgram() = 0;
	virtual void invalidSelection() = 0;

	virtual void showProductsMenu() = 0;
	virtual void showTitlesOfProducts(string productType) = 0;
};


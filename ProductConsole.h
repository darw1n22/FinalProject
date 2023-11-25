#pragma once
#include "Console.h"

class ProductConsole : public Console
{
public:
	void showProductsMenu() override;
	void showTitlesOfProducts(string productType) override;
};


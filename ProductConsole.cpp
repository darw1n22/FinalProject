#include "pch.h"
#include "ProductConsole.h"

void ProductConsole::showProductsMenu()
{
    system("CLS");
    cout << "1. Clothing" << endl;
    cout << "2. Shoes" << endl;
    cout << "3. Balls" << endl;
    cout << "4. Accessories" << endl;
    cout << "5. All products" << endl;
    cout << "0. Return to main manu" << endl;
}

void ProductConsole::showTitlesOfProducts(string productType)
{
    cout << "******************** " << productType << "******************** " << endl;
}

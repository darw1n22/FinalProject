#include "pch.h"
#include "Console.h"

void Console::printEndline()
{
    cout << endl;
}

void Console::printSeparator()
{
    cout << "--------------------------------------------------------" << endl;
}

void Console::printSpace()
{
    cout << " ";
}

void Console::showMainMenu()
{
    system("CLS");
    cout << "_____Person Store_______" << endl;
    cout << "1. Register a Client" << endl;
    cout << "2. Register a Staff Member" << endl;
    cout << "3. Register the Owner" << endl;
    cout << "4. Edit Person Information" << endl;
    cout << "5. Show Person Info" << endl;
    cout << "6. Show Client by type (Premium or Standard)" << endl;
    cout << "7. make a purchase" << endl;
    cout << "8. Register a product" << endl;
    cout << "9. show Product" << endl;
    cout << "10. Raise salary of staff member" << endl;
    cout << "11. Search a product" << endl;
    cout << "12. Show full inventory" << endl;
    cout << "13. Edit data based on the amount of employees and clients" << endl;
    cout << "0. Exit the menu" << endl;
    cout << "Please enter a valid option: ";
}

template <typename T>
T Console::readFromKeyboard()
{
    T attribute;
    cin >> attribute;
    return attribute;
}

void Console::completedProgram()
{
    cout << "Thank you for your Store!!! Have a good day..." << endl;
}

void Console::invalid()
{
    cout << "Invalid argument. Please enter a valid argument next time!" << endl;
}

void Console::returnToPreviousMenu()
{
    cout << "Returning to the previous menu!" << endl;
}

void Console::fireEmployee()
{
    cout << "Do you want to fire anyone?(1. Yes or  2. No): ";
}

void Console::numberOfFire()
{
    cout << "How many employees do you want to fire?: ";
}

void Console::hireEmployee()
{
    cout << "Do you want to hire anyone?(1. Yes or  2. No): ";
}

void Console::numberOfHire()
{
    cout << "How many employees do you want to hire?: ";
}

void Console::showProductsMenu()
{
    system("CLS");
    cout << "1. Clothing" << endl;
    cout << "2. Shoes" << endl;
    cout << "3. Balls" << endl;
    cout << "4. Accessories" << endl;
    cout << "5. All products" << endl;
    cout << "0. Return to main manu" << endl;
    cout << "Please enter a valid option: ";
}

void Console::showTitlesOfProducts(string productType)
{
    cout << "******************** " << productType << "******************** " << endl;
}

void Console::selectProduct()
{
    cout << "1) Clothing | 2) Shoes | 3) Balls | 4) Accessory" << endl;
}

void Console::searchProducts()
{
    cout << "What type of product do you want search" << endl;
    Console::selectProduct();
}

void Console::searchProductsMenu()
{
    cout << "1. Search by code" << endl;
    cout << "2. Search by brand" << endl;
    cout << "3. Search by price" << endl;
    cout << "4. Search by color" << endl;
}

void Console::searchClothing()
{
    Console::searchProductsMenu();
    cout << "5. Search by size" << endl;
    cout << "6. Search by type of garment" << endl;
}

void Console::searchShoes()
{
    Console::searchProductsMenu();
    cout << "5. Search by size" << endl;
}

void Console::searchBall()
{
    Console::searchProductsMenu();
    cout << "5. Search by sport" << endl;
}

void Console::searchAccessories()
{
    Console::searchAccessories();
    cout << "5. Search by body part" << endl;
}

void Console::enterProductCode()
{
    cout << "Enter the code: ";
}

int Console::amountOfProducts()
{
    int amountOfProducts;
    cout << "--REGISTERING PRODUCTS--" << endl;
    cout << "Amount of new types of products: (1 - 4)" << endl;
    cout << " Clothing |||  Shoes |||  Ball |||  Accesory" << endl;
    cin >> amountOfProducts;
    return amountOfProducts;
}

void Console::showProductInformation(long productCode, string brand, string type, string color, int stock, int shelf, float price)
{
    cout << "Product code: " << productCode << endl;
    cout << "Brand: " << brand << endl;
    cout << "Color: " << color << endl;
    cout << "Type: " << type << endl;
    cout << "Stock: " << stock << " unities" << endl;
    cout << "It is on shelf number " << shelf << endl;
    cout << "Price: " << price << endl;
}

void Console::showAccessory(string bodyPart)
{
    cout << "The accessory is for " << bodyPart << endl;
}

void Console::showBall(int weight, string sport)
{
    cout << "Weight: " << weight << endl;
    cout << "Sport: " << sport << endl;
}

void Console::showSizes()
{
    cout << "available sizes: ";
    
}

void Console::printSizes(int size)
{
    cout << size << " ";
}

void Console::enterTheSize()
{
    cout << "Enter the size: ";
}

void Console::enterTheBrand()
{
    cout << "Enter the brand: ";
}

void Console::enterThePrice()
{
    cout << "Enter the price: ";
}

void Console::enterTheColor()
{
    cout << "Enter the color: ";
}

void Console::enterTheGarment()
{
    cout << "Enter the type of garment: ";
}

void Console::enterTheSport()
{
    cout << "For which sport: ";
}

void Console::enterBodyPart()
{
    cout << "Enter the body part: ";
}

void Console::enterTheWeight()
{
    cout << "Enter the weight of ball: ";
}

void Console::readProducts(long& productCode, string& brand, string& color,int &typeOption, int& stock, int& shelf, float& price)
{
    Console::enterProductCode();
    productCode = Console::readFromKeyboard<long>();
    Console::enterTheBrand();
    brand = Console::readFromKeyboard<string>();
    cout << "Enter the stock: ";
    stock = Console::readFromKeyboard<int>();
    cout << "Enter the color of the product: ";
    color = Console::readFromKeyboard<string>();
    Console::selectProduct();
    typeOption = Console::readFromKeyboard<int>();
    cout << "Enter the number of shelf for to save the product: ";
    shelf = Console::readFromKeyboard<int>();
    Console::enterThePrice();
    price = Console::readFromKeyboard<float>();
}

void Console::showClientsAndEmployeesMenu()
{
    system("CLS");
    cout << "---Menu---" << endl;
    cout << "1. Display Registered Employees and Clients" << endl;
    cout << "2. Adjust Salaries and Budgets" << endl;
    cout << "3. Adjust Promotions" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
}

void Console::enterPersonId()
{
    cout << "Enter the id: ";
}

void Console::inactivePromotion()
{
    cout << "No promotions available at the moment." << endl;
}

void Console::invoiceDesing(Client* clientToBuy, Staff* staffToSell, vector<Product*> productsSold, float amountOfPurchase)
{
    cout << clientToBuy->getId();
    Console::printSpace();
    cout << clientToBuy->getName();
    Console::printSpace();
    cout << clientToBuy->getLastname();
    Console::printEndline();
    Console::printSeparator();
    for (Product* product : productsSold)
    {
        cout << product->getProductCode();
        Console::printSpace();
        cout << product->getType();
        Console::printSpace();
        cout << product->getBrand();
        Console::printSpace();
        cout << product->getStock();
        Console::printSpace();
        cout << product->getPrice() * product->getStock();
        Console::printEndline();
    }
    Console::printSeparator();
    cout << amountOfPurchase;
    Console::printEndline();
    Console::printSeparator();
    cout << staffToSell->getId();
    Console::printSpace();
    cout << staffToSell->getName();
    Console::printSpace();
    cout << staffToSell->getLastname();
    Console::printSpace();
    cout << staffToSell->getJobTitle();
    Console::printEndline();
}

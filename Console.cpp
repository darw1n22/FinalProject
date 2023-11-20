#include "pch.h"
#include "Console.h"

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
    cout << "0. Exit the menu" << endl;
    cout << "Please enter a valid option: ";
}

int Console::selectOption()
{
    int option;
    cin >> option;
    return option;
}

void Console::completedProgram()
{
    cout << "Thank you for your Store!!! Have a good day..." << endl;
}

void Console::invalidSelection()
{
    cout << "Invalid choice. Please enter a valid choice next time!" << endl;
}

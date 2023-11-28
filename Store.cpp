#include "pch.h"
#include "Store.h"

int Store::employeeCount = 0;
int Store::clientCount = 0;

Store::Store()
{
}
Store::~Store()
{
    for (Person* person : people) {
        delete person;
    }
    for (Staff* staff : staffs) {
        delete staff;
    }
    for (Client* client : clients) {
        delete client;
    }
    for (Clothing* clothing : clothes)
    {
        delete clothing;
    }
    for (Shoe* shoe : shoes)
    {
        delete shoe;
    }
    for (Ball* ball : balls)
    {
        delete ball;
    }
    for (Accessory* accessory : accessories)
    {
        delete accessory;
    }
    for (Product* product : products)
    {
        delete product;
    }
    if (owner != nullptr)
    {
        delete owner;
    }
}

void Store::displayCount()
{
    cout << "Registered Employees: " << employeeCount << endl;
    cout << "Registered Clients: " << clientCount << endl;
}

void Store::addPersonInfo(long& id, long& phone, string& name, string& lastname, string& email, string& address, int& gender, int& age) {
    Person* person;
    cout << "Enter the person's ID: ";
    cin >> id;
    if (id < 1) {
        cout << "Invalid input for ID. Please enter a valid number greater than 0." << endl;
        return;
    }
    cout << "Enter the person's first name: ";
    cin >> name;

    cout << "Enter the person's last name: ";
    cin >> lastname;
    cout << "Enter the person's gender (1. Male, 2. Female, 3. Prefer not to say): ";
    cin >> gender;
    if (gender < 1 || gender > 3) {
        cout << "Invalid input for gender. Please enter a valid option (1, 2, or 3)." << endl;
        return;
    }
    cout << "Enter the person's email address: ";
    cin >> email;
    cout << "Enter the person's address: ";
    cin >> address;
    cout << "Enter the person's phone number: ";
    cin >> phone;
    if (phone < 1) {
        cout << "Invalid input for phone number. Please enter a valid number." << endl;
        return;
    }
    cout << "Enter the person's age: ";
    cin >> age;
    if (age < 0 || age>150) {
        cout << "Invalid input for age. Please enter a valid age (a non-negative number) or a number less than 150." << endl;
        return;
    }
    person = new Person(id, name, lastname, gender, email, address, phone, age);
    people.push_back(person);
}
void Store::registerClient()
{
    long id, phone;
    string name, lastname, email, address;
    int gender, age, numPurchases;
    addPersonInfo(id, phone, name, lastname, email, address, gender, age);
    if (id <= 0) {
        return;
    }
    if (gender < 1 || gender > 3) {
        return;
    }
    if (phone < 1) {
        return;
    }
    if (age < 0 || age>150) {
        return;
    }
    bool isPremium;
    float purchases, totalPurchases;
    cout << "Enter the amount purchased this session: ";
    cin >> purchases;
    if (purchases < 0) {
        cout << "Invalid input for purchases. purchases mus be a non negative number." << endl;
        return;
    }
    cout << "Enter the amount purchased in previous sessions: ";
    cin >> totalPurchases;
    if (totalPurchases < 0) {
        cout << "Invalid input for totalPurchases. totalPurchases mus be a non negative number." << endl;
        return;

    }
    cout << "Enter the total number of items the client purchased: ";
    cin >> numPurchases;
    if (numPurchases < 0) {
        cout << "Invalid input for the number of purchases. the number of purchases must be greater than -1." << endl;
        return;
    }
    cout << "Is the client premium? (1 for Premium (note client has have to had purchased more than 14 items), 0 for Standard): ";
    cin >> isPremium;
    if ((isPremium != 0 && isPremium != 1)) {
        cout << "Invalid input for client type. Please enter 1 for Premium or 0 for Standard." << endl;
        return;
    }
    else {
        if (numPurchases < 15) {
            isPremium = 0;
        }
        else
        {
            isPremium = 1;
        }
    }
    totalPurchases = purchases + totalPurchases;
    Client* client = new Client(id, name, lastname, gender, email, address, phone, age, isPremium, purchases, totalPurchases, numPurchases);
    clients.push_back(client);
}
void Store::editClientInfo()
{
    long id;
    long newPhone;
    int newGender, newAge;
    string newName, newLastname, newEmail, newAddress;
    cout << "Enter the client's id: ";
    cin >> id;
    if (id < 1) {
        cout << "Invalid input for ID. Please enter a valid number greater than 0." << endl;
        return;
    }
    Client* newClient = nullptr;
    int newnumPurchases;
    bool newIsPremium;
    float newPurchases;
    float newTotalPurchases;
    for (Client* client : clients) {
        if (client->getId() == id) {
            cout << "Enter the new name of the person: ";
            cin >> newName;
            client->setName(newName);
            cout << "Enter the new last name of the person: ";
            cin >> newLastname;
            client->setLastname(newLastname);
            cout << "Enter the new gender of the person: (1 for male, 2 for female, 3 for other): ";
            cin >> newGender;
            if (newGender < 1 || newGender > 3) {
                cout << "Invalid input for gender. Please enter a valid option (1, 2, or 3)." << endl;
                return;
            }
            client->setGender(newGender);
            cout << "Enter the new age of the person: ";
            cin >> newAge;
            if (newAge < 0 || newAge>150) {
                cout << "Invalid input for age. Please enter a valid age (a non-negative number) or a number less than 150." << endl;
                return;
            }
            client->setAge(newAge);
            cout << "Enter the new phone number of the person: ";
            cin >> newPhone;
            if (newPhone < 1) {
                cout << "Invalid input for phone number. Please enter a valid number." << endl;
                return;
            }
            client->setPhone(newPhone);
            cout << "Enter the new email of the person: ";
            cin >> newEmail;
            client->setEmail(newEmail);
            cout << "Enter the new address of the person: ";
            cin >> newAddress;
            client->setAddress(newAddress);
            cout << "Enter the new amount purchased in the most recent session: ";
            cin >> newPurchases;
            if (newPurchases < 0) {
                cout << "Invalid input for purchases. purchases mus be a non negative number." << endl;
                return;
            }
            client->setPurchases(newPurchases);
            cout << "Enter the new amount purchased in all other sessions (minus the most recent one): ";
            cin >> newTotalPurchases;
            if (newTotalPurchases < 0) {
                cout << "Invalid input for totalPurchases. totalPurchases mus be a non negative number." << endl;
                return;

            }
            newTotalPurchases = newTotalPurchases + newPurchases;
            client->setTotalPurchases(newTotalPurchases);
            cout << "Enter the new number of purchases the client made: ";
            cin >> newnumPurchases;
            if (newnumPurchases < 0) {
                cout << "Invalid input for the number of purchases. the number of purchases must be greater than -1." << endl;
                return;
            }
            client->setNumPurchases(newnumPurchases);
            cout << "Enter if the client is still premium (1 for Premium (note client has have to had purchased more than 14 items), 0 for Standard): ";
            cin >> newIsPremium;
            if ((newIsPremium != 0 && newIsPremium != 1)) {
                cout << "Invalid input for client type. Please enter 1 for Premium or 0 for Standard." << endl;
                return;
            }
            else
            {
                if (newnumPurchases < 15) {
                    client->setIsPremium(0);
                }
                else
                {
                    client->setIsPremium(1);
                }
            }
            newClient = client;
        }
    }
    if (newClient == nullptr) {
        cout << "Invalid id. please try again next time." << endl;
        return;
    }
}
void Store::registerStaff()
{

    long id, phone;
    string name, lastname, email, address;
    int gender, age;
    addPersonInfo(id, phone, name, lastname, email, address, gender, age);
    string jobTitle, profession;
    int salary, experience, productsSold = 0;
    if (id <= 0) {
        return;
    }
    if (gender < 1 || gender > 3) {
        return;
    }
    if (phone < 1) {
        return;
    }
    if (age < 0 || age>150) {
        return;
    }
    cout << "Enter the staff's job title: ";
    cin >> jobTitle;
    cout << "Enter the staff's profession: ";
    cin >> profession;
    cout << "Enter the staff's salary: ";
    cin >> salary;
    if (salary < 1) {
        cout << "Invalid input for the salary. Salary must be greater than or equal to 1." << endl;
        return;
    }
    cout << "Enter the staff's years of experience: ";
    cin >> experience;
    if (experience < 0) {
        cout << "Invalid input for the years of experience. Experience must be a non-negative number." << endl;
        return;
    }
    Staff* staff = new Staff(id, name, lastname, gender, email, address, phone, age, jobTitle, profession, salary, experience, productsSold);
    staffs.push_back(staff);
}
void Store::editStaffInfo()
{
    long id;
    long newPhone;
    int newGender, newAge;
    string newName, newLastname, newEmail, newAddress;
    cout << "Enter the staff's id: ";
    cin >> id;
    if (id < 1) {
        cout << "Invalid input for ID. Please enter a valid number greater than 0." << endl;
        return;
    }
    Staff* newStaff = nullptr;
    string newJobTitle, newProfession;
    int newSalary, newExperience, newproductsSold;
    for (Staff* staff : staffs) {
        if (staff->getId() == id) {
            cout << "Enter the new name of the person: ";
            cin >> newName;
            staff->setName(newName);
            cout << "Enter the new last name of the person: ";
            cin >> newLastname;
            staff->setLastname(newLastname);
            cout << "Enter the new gender of the person: (1 for male, 2 for female, 3 for other): ";
            cin >> newGender;
            if (newGender < 1 || newGender > 3) {
                cout << "Invalid input for gender. Please enter a valid option (1, 2, or 3)." << endl;
                return;
            }
            staff->setGender(newGender);
            cout << "Enter the new age of the person: ";
            cin >> newAge;
            if (newAge < 0 || newAge>150) {
                cout << "Invalid input for age. Please enter a valid age (a non-negative number) or a number less than 150." << endl;
                return;
            }
            staff->setAge(newAge);
            cout << "Enter the new phone number of the person: ";
            cin >> newPhone;
            if (newPhone < 1) {
                cout << "Invalid input for phone number. Please enter a valid number." << endl;
                return;
            }
            staff->setPhone(newPhone);
            cout << "Enter the new email of the person: ";
            cin >> newEmail;
            staff->setEmail(newEmail);
            cout << "Enter the new address of the person: ";
            cin >> newAddress;
            staff->setAddress(newAddress);
            cout << "Enter the new job title of the person: ";
            cin >> newJobTitle;
            staff->setJobTitle(newJobTitle);
            cout << "Enter the new profession of the person: ";
            cin >> newProfession;
            staff->setProfession(newProfession);
            cout << "Enter the new salary of the person: ";
            cin >> newSalary;
            if (newSalary < 1) {
                cout << "Invalid input for the salary. Salary must be greater than or equal to 1." << endl;
                return;
            }
            staff->setSalary(newSalary);
            cout << "Enter the new years of experience of the person: ";
            cin >> newExperience;
            if (newExperience < 0) {
                cout << "Invalid input for the years of experience. Experience must be a non-negative number." << endl;
                return;
            }
            staff->setExperience(newExperience);
            newStaff = staff;
            cout << "Enter the amount of product sold by the staff: ";
            cin >> newproductsSold;
            if (newproductsSold < 0) {
                cout << "Invalid input for the amount of products sold. Products sold must be greater than or equal to 0." << endl;
                return;
            }
            staff->setProductsSold(newproductsSold);
        }
    }
    if (newStaff == nullptr) {
        cout << "Invalid id. please try again next time." << endl;
        return;
    }
}
void Store::registerOwner()
{
    if (owner) {
        cout << "An owner is already registered. Cannot register another owner. try editing person info instead." << endl;
        return;
    }
    long id, phone;
    string name, lastname, email, address;
    int gender, age;
    addPersonInfo(id, phone, name, lastname, email, address, gender, age);
    int budget;
    if (id <= 0) {
        return;
    }
    if (gender < 1 || gender > 3) {
        return;
    }
    if (phone < 1) {
        return;
    }
    if (age < 0 || age>150) {
        return;
    }
    cout << "Enter the owner's budget: ";
    cin >> budget;
    if (budget < 0) {
        cout << "invalid input for budget. The budget must be a non-negative number." << endl;
        return;
    }
    Owner* newOwner = new Owner(id, name, lastname, gender, email, address, phone, age, budget);
    owner = newOwner;
}
void Store::editOwnerInfo()
{
    long id;
    long newPhone;
    int newGender, newAge;
    string newName, newLastname, newEmail, newAddress;
    cout << "Enter the owner's id: ";
    cin >> id;
    if (id < 1) {
        cout << "Invalid input for ID. Please enter a valid number greater than 0." << endl;
        return;
    }
    int newBudget;
    if (owner->getId() == id) {
        cout << "Enter the new name of the person: ";
        cin >> newName;
        owner->setName(newName);
        cout << "Enter the new last name of the person: ";
        cin >> newLastname;
        owner->setLastname(newLastname);
        cout << "Enter the new gender of the person: (1 for male, 2 for female, 3 for other): ";
        cin >> newGender;
        if (newGender < 1 || newGender > 3) {
            cout << "Invalid input for gender. Please enter a valid option (1, 2, or 3)." << endl;
            return;
        }
        owner->setGender(newGender);
        cout << "Enter the new age of the person: ";
        cin >> newAge;
        if (newAge < 0 || newAge>150) {
            cout << "Invalid input for age. Please enter a valid age (a non-negative number) or a number less than 150." << endl;
            return;
        }
        owner->setAge(newAge);
        cout << "Enter the new phone number of the person: ";
        cin >> newPhone;
        if (newPhone < 1) {
            cout << "Invalid input for phone number. Please enter a valid number." << endl;
            return;
        }
        owner->setPhone(newPhone);
        cout << "Enter the new email of the person: ";
        cin >> newEmail;
        owner->setEmail(newEmail);
        cout << "Enter the new address of the person: ";
        cin >> newAddress;
        owner->setAddress(newAddress);
        cout << "Enter the new budget of the owner: ";
        cin >> newBudget;
        if (newBudget < 0) {
            cout << "invalid input for budget. The budget must be a non-negative number." << endl;
            return;
        }
        owner->setBudget(newBudget);
    }
    else {
        cout << "Invalid id. please try again next time." << endl;
        return;
    }
}
void Store::editSalary()
{
    long id;
    int newSalary;
    cout << "Enter the id of the staff member whose salary you want to edit: ";
    cin >> id;
    if (id < 1) {
        cout << "Invalid input for ID. Please enter a valid number greater than 0." << endl;
        return;
    }
    Staff* newStaff = nullptr;
    for (Staff* staff : staffs)
    {
        if (staff->getId() == id)
        {
            cout << staff->getName() << " " << staff->getLastname() << " " << staff->getSalary() << endl;
            cout << "Enter the new salary of the staff member: ";
            cin >> newSalary;
            if (newSalary < 1) {
                cout << "Invalid input for the salary. Salary must be greater than or equal to 1." << endl;
                return;
            }
            staff->setSalary(newSalary);
            newStaff = staff;
        }
    }
    if (newStaff == nullptr) {
        cout << "Invalid id. please try again next time." << endl;
        return;
    }
}
void Store::EditPersonInfo()
{
    int choice;
    do {
        system("CLS");
        cout << "Select the type of person you want to edit:" << endl;
        cout << "1. Edit Client" << endl;
        cout << "2. Edit Staff Member" << endl;
        cout << "3. Edit Owner" << endl;
        cout << "4. Edit salary" << endl;
        cout << "5. Return to the main menu" << endl;
        cout << "Please enter a valid option: ";
        cin >> choice;
        switch (choice) {
        case 1:
            editClientInfo();
            cout << "Press any key to return to the menu!";
            _getch();
            break;
        case 2:
            editStaffInfo();
            cout << "Press any key to return to the menu!";
            _getch();
            break;
        case 3:
            editOwnerInfo();
            cout << "Press any key to return to the menu!";
            _getch();
            break;
        case 4:
            editSalary();
            cout << "Press any key to return to the menu!";
            _getch();
            break;
        case 5:
            cout << "Thank you for editing information" << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a valid choice next time!" << endl;
            cout << "Press any key to return to the menu!";
            _getch();
        }
    } while (choice != 5);
}
void Store::showPersonInfo()
{
    cout << "Select the type of person you want to view (Client, Staff, Owner): ";
    string personType;
    cin >> personType;
    if (personType == "Client") {
        for (Client* client : clients) {
            client->displayInfo();
        }
    }
    else if (personType == "Staff") {
        for (Staff* staff : staffs) {
            staff->displayInfo();
        }
    }
    else if (personType == "Owner" && owner) {
        owner->displayInfo();
    }
    else {
        cout << "Invalid person type or no persons of the selected type found." << endl;
    }
}
void Store::showClientByType()
{
    int clientType;
    cout << "Enter the client type (1 for Premium, 0 for Standard): ";
    cin >> clientType;
    if (clientType != 0 && clientType != 1) {
        cout << "Invalid input for client type. Please enter 1 for Premium or 0 for Standard." << endl;
        return;
    }
    if (clientType == 1) {
        int num_premium = 0;
        cout << "Premium clients" << endl;
        for (Client* client : clients) {
            if (client->getIsPremium() == true)
            {
                client->displayInfo();
                num_premium++;

            }
        }
        cout << "Number of premium clients: " << num_premium << endl;
    }
    else
    {
        int num_standard = 0;
        cout << "Standard clients" << endl;
        for (Client* client : clients) {
            if (client->getIsPremium() == false)
            {
                client->displayInfo();
                num_standard++;

            }
        }
        cout << "Number of standard clients: " << num_standard << endl;
    }
}
void Store::makePurchase()
{
    long clientId, staffId, productCode;
    Client* clientToBuy = nullptr;
    Staff* staffToSell = nullptr;
    Product* productToBuy = nullptr;
    vector <Product*> productsPurchased;
    int quantity;
    cout << "Enter the client's ID: ";
    cin >> clientId;
    cout << "Enter the staff's ID: ";
    cin >> staffId;
    for (Client* client : clients) {
        if (client->getId() == clientId) {

            clientToBuy = client;
        }
    }
    for (Staff* staff : staffs) {
        if (staff->getId() == staffId) {

            staffToSell = staff;
        }
    }
    if (staffToSell == nullptr || clientToBuy == nullptr || clientId == staffId) {
        cout << "Invalid staff or client code or the staff and client codes are the same. Please try again next time!" << endl;
        return;
    }
    cout << "Enter the product code: ";
    cin >> productCode;
    for (Product* product : products) {
        if (product->getProductCode() == productCode) {
            productToBuy = product;
            cout << "Enter the quantity of the product to purchase: ";
            cin >> quantity;
            if (quantity < 1) {
                cout << "Invalid input for quantity. The quantity of the product must be greater than or equal to 1." << endl;
                return;
            }
            if (quantity > productToBuy->getStock()) {
                cout << "You can't buy the product as you are trying to buy a quantity greater than the stock of the product!!!" << endl;
                return;
            }
            else
            {
                productToBuy->setStock(productToBuy->getStock() - quantity);
            }
            product->setStock(quantity);
            productsPurchased.push_back(product);
        }
    }
    if (productToBuy == nullptr) {
        cout << "Product not found. Please check the product code." << endl;
        return;
    }

    float productPrice = productToBuy->getPrice() * quantity;
    if (clientToBuy->getIsPremium()) {
        productPrice *= 0.85;
    }
    float totalPurchases = productPrice + clientToBuy->getTotalPurchases();
    int numPurchases = quantity + clientToBuy->getNumPurchases();
    int productsSold = quantity + staffToSell->getProductsSold();
    clientToBuy->setPurchases(productPrice);
    clientToBuy->setTotalPurchases(totalPurchases);
    clientToBuy->setNumPurchases(numPurchases);
    staffToSell->setProductsSold(productsSold);
    cout << "Purchase successful!" << endl;
    cout << "Product: " << productToBuy->getProductCode() << endl;
    cout << "Product Brand: " << productToBuy->getBrand() << endl;
    cout << "Product Type: " << productToBuy->getType() << endl;
    cout << "Total Price of the items: " << productPrice << endl;
    cout << "Total Purchases of the client: " << totalPurchases << endl;
    Invoice* newInvoice = new Invoice(clientToBuy, staffToSell, productsPurchased, totalPurchases);
    sales.push_back(newInvoice);
    newInvoice->showInvoice();
}
void Store::purchaseMenu()
{
    int choice;
    do {
        system("CLS");
        cout << "_____Product Purchase Menu_____" << endl;
        cout << "1. Buy a Product" << endl;
        cout << "2. Exit" << endl;
        cout << "Please enter a valid option: ";
        cin >> choice;

        switch (choice) {
        case 1:
            makePurchase();
            cout << "Press any key to return to the menu!";
            _getch();
            break;
        case 2:
            cout << "Exiting the Product Purchase Menu." << endl;
            cout << "Press any key to return to the menu!";
            break;
        default:

            cout << "Invalid choice. Please enter a valid option." << endl;
            cout << "Press any key to return to the menu!";
            _getch();
        }

    } while (choice != 2);
}
void Store::raiseSalaryDependingOnNumberSold()
{
    int staffID;
    Staff* staffToRaise = nullptr;
    cout << "Enter the id of the staff member to raise salary: ";
    cin >> staffID;
    for (Staff* staff : staffs) {
        if (staff->getId() == staffID) {
            staffToRaise = staff;
        }
    }
    if (staffToRaise == nullptr) {
        cout << "No valid staff found by id. Please try again next time." << endl;
        return;
    }
    if (staffToRaise->getProductsSold() >= 5 && staffToRaise->getProductsSold() < 20) {
        staffToRaise->setSalary(staffToRaise->getSalary() + (50 * (staffToRaise->getProductsSold() / 5)));
        return;

    }
    if (staffToRaise->getProductsSold() >= 20 && staffToRaise->getProductsSold() < 100) {
        staffToRaise->setSalary(staffToRaise->getSalary() + (200 * (staffToRaise->getProductsSold() / 20)));
        return;

    }
    if (staffToRaise->getProductsSold() >= 100) {
        staffToRaise->setSalary(staffToRaise->getSalary() + (800 * (staffToRaise->getProductsSold() / 100)));
        return;
    }

}
void Store::registerAProduct()
{
    long productCode;
    string brand, type, sport, garment;
    int typeOption, stock, shelf, size;
    float price;
    int accumulatingCost = 0;
    int amountOfProducts = Console::amountOfProducts();
    system("cls");

    for (int i = 1; i <= amountOfProducts; i++) {
        Console::readProducts(productCode, brand, sport, typeOption, stock, shelf, price);
        switch (typeOption)
        {
        case 1:
        {
            type = "Clothing";
            vector <int> clothingSize;
            Console::enterTheGarment();
            garment = Console::readFromKeyboard<string>();
            for (int i = 0; i < stock; i++)
            {
                size = 0;
                Console::enterTheSize();
                size = Console::readFromKeyboard<int>();
                clothingSize.push_back(size);
            }
            Clothing* newClothing = new Clothing(clothingSize, garment, productCode, brand, type, stock, shelf, price);
            accumulatingCost = accumulatingCost + newClothing->getTotalCost();
            cout << "Accumulated cost until now: " << accumulatingCost << endl;
            system("pause");
            clothes.push_back(newClothing);
            products.push_back(newClothing);
            break;
        }
        case 2:
        {
            type = "Shoe";
            vector <int> shoeSize;
            for (int i = 0; i < stock; i++)
            {
                size = 0;
                Console::enterTheSize();
                size = Console::readFromKeyboard<int>();
                shoeSize.push_back(size);
            }
            Shoe* newShoe = new Shoe(shoeSize, productCode, brand, type, stock, shelf, price);
            accumulatingCost = accumulatingCost + newShoe->getTotalCost();
            cout << "Accumulated cost until now: " << accumulatingCost << endl;
            system("pause");
            shoes.push_back(newShoe);
            products.push_back(newShoe);
            break;
        }
        case 3:
        {
            type = "Ball";
            int weight;
            Console::enterTheWeight();
            weight = Console::readFromKeyboard<int>();
            Ball* newBall = new Ball(weight, sport, productCode, brand, type, stock, shelf, price);
            accumulatingCost = accumulatingCost + newBall->getTotalCost();
            cout << "Accumulated cost until now: " << accumulatingCost << endl;
            system("pause");
            balls.push_back(newBall);
            products.push_back(newBall);
            break;
        }
        case 4:
        {
            type = "Accessory";
            string bodyPart;
            Console::enterBodyPart();
            bodyPart = Console::readFromKeyboard<string>();
            Accessory* newAccessory = new Accessory(bodyPart, productCode, brand, type, stock, shelf, price);
            accumulatingCost = accumulatingCost + newAccessory->getTotalCost();
            cout << "Accumulated cost until now: " << accumulatingCost << endl;
            system("pause");
            accessories.push_back(newAccessory);
            products.push_back(newAccessory);
            break;
        }
        default:
        {
            Console::invalid();
            break;
        }
        }
        system("cls");
    }
    cout << "Presupuesto previo: " << owner->getBudget() << endl;
    int currentBudget = owner->getBudget();
    int newBudget = currentBudget - accumulatingCost;
    owner->setBudget(newBudget);
    cout << "Presupuesto ha sido actualizado exitosamente!" << endl;
    cout << "Presupuesto despues de hacer las compras del proveedor: " << newBudget << endl;
}
void Store::showProduct()
{
    long code;
    int typeOption;
    Console::selectProduct();
    typeOption = Console::readFromKeyboard<int>();
    Console::enterProductCode();
    code = Console::readFromKeyboard<long>();
    switch (typeOption)
    {
    case 1:
    {
        for (Clothing* clothing : clothes)
        {
            if (clothing->productCode == code)
            {
                clothing->showInfo();
            }
        }
        break;
    }
    case 2:
    {
        for (Shoe* shoe : shoes)
        {
            if (shoe->productCode == code)
            {
                shoe->showInfo();
            }
        }
        break;
    }
    case 3:
    {
        for (Ball* ball : balls)
        {
            if (ball->productCode == code)
            {
                ball->showInfo();
            }
        }
        break;
    }
    case 4:
    {
        for (Accessory* accessory : accessories)
        {
            if (accessory->productCode == code)
            {
                accessory->showInfo();
            }
        }
        break;
    }

    }
}

void Store::searchAProduct()
{
    int typeOption;
    Console::searchProducts();
    typeOption = Console::readFromKeyboard<int>();
    switch (typeOption)
    {
    case 1:
    {
        int option;
        Console::searchClothing();
        option = Console::readFromKeyboard<int>();
        switch (option)
        {
        case 1:
        {
            int code;
            Console::enterProductCode();
            code = Console::readFromKeyboard<int>();
            for (Clothing* clothing : clothes)
            {
                if (clothing->productCode == code)
                {
                    clothing->showInfo();
                }
            }
            break;
        }
        
        case 2:
        {
            string brand;
            brand = Console::readFromKeyboard<string>();
            for (Clothing* clothing : clothes)
            {
                if (clothing->brand == brand)
                {
                    clothing->showInfo();
                    Console::printSeparator();
                }
            }
            break;
        }
        case 3:
        {
            float price;
            Console::enterThePrice();
            price = Console::readFromKeyboard<float>();
            for (Clothing* clothing : clothes)
            {
                if (clothing->price <= price)
                {
                    clothing->showInfo();
                    Console::printSeparator();
                }
            }
            break;
        }
        case 4:
        {
            string color;
            Console::enterTheColor();
            color = Console::readFromKeyboard<string>();
            for (Clothing* clothing : clothes)
            {
                if (clothing->color == color)
                {
                    clothing->showInfo();
                    Console::printSeparator();
                }
            }
            break;
        }
        case 5:
        {
            int size;
            Console::enterTheSize();
            size = Console::readFromKeyboard<int>();
            for (Clothing* clothing : clothes)
            {
                vector <int> sizes = clothing->getClothingSize();
                for (int clotheSize : sizes)
                {
                    if (clotheSize == size)
                    {
                        clothing->showInfo();
                        Console::printSeparator();
                    }
                }
            }
            break;
        }
        case 6:
        {
            string garment;
            Console::enterTheGarment();
            garment = Console::readFromKeyboard<string>();
            for (Clothing* clothing : clothes)
            {
                if (clothing->getGarment() == garment)
                {
                    clothing->showInfo();
                    Console::printSeparator();
                }
            }
            break;
        }
        }
        break;
    }
    case 2:
    {
        int option;
        Console::searchProductsMenu();
        option = Console::readFromKeyboard<int>();
        switch (option)
        {
        case 1:
        {
            long code;
            Console::enterProductCode();
            code = Console::readFromKeyboard<long>();
            for (Shoe* shoe : shoes)
            {
                if (shoe->productCode == code)
                {
                    shoe->showInfo();
                }
            }
            break;
        }
        case 2:
        {
            string brand;
            Console::enterTheBrand();
            brand = Console::readFromKeyboard<string>();
            for (Shoe* shoe : shoes)
            {
                if (shoe->brand == brand)
                {
                    shoe->showInfo();
                    Console::printSeparator();
                }
            }
            break;
        }
        case 3:
        {
            float price;
            Console::enterThePrice();
            price = Console::readFromKeyboard<float>();
            for (Shoe* shoe : shoes)
            {
                if (shoe->price <= price)
                {
                    shoe->showInfo();
                    Console::printSeparator();
                }
            }
            break;
        }
        case 4:
        {
            string color;
            Console::enterTheColor();
            color = Console::readFromKeyboard<string>();
            for (Shoe* shoe : shoes)
            {
                if (shoe->color == color)
                {
                    shoe->showInfo();
                    Console::printSeparator();
                }
            }
            break;
        }
        case 5:
        {
            int size;
            Console::enterTheSize();
            size = Console::readFromKeyboard<int>();
            for (Shoe* shoe : shoes)
            {
                vector <int> sizes = shoe->getShoeSize();
                for (int shoeSize : sizes)
                {
                    if (shoeSize == size)
                    {
                        shoe->showInfo();
                        Console::printSeparator();
                    }
                }
            }
            break;
        }
        }
        break;
    }
    case 3:
    {
        int option;
        Console::searchBall();
        option = Console::readFromKeyboard<int>();
        switch (option)
        {
        case 1:
        {
            long code;
            Console::enterProductCode();
            code = Console::readFromKeyboard<long>();
            for (Ball* ball : balls)
            {
                if (ball->productCode == code)
                {
                    ball->showInfo();
                    Console::printSeparator();
                }
            }
            break;
        }
        case 2:
        {
            string brand;
            Console::enterTheBrand();
            brand = Console::readFromKeyboard<string>();
            for (Ball* ball : balls)
            {
                if (ball->brand == brand)
                {
                    ball->showInfo();
                    Console::printSeparator();
                }
            }
            break;
        }
        case 3:
        {
            float price;
            Console::enterThePrice();
            price = Console::readFromKeyboard<float>();
            for (Ball* ball : balls)
            {
                if (ball->price <= price)
                {
                    ball->showInfo();
                    Console::printSeparator();
                }
            }
            break;
        }
        case 4:
        {
            string color;
            Console::enterTheColor();
            color = Console::readFromKeyboard<string>();
            for (Ball* ball : balls)
            {
                if (ball->color == color)
                {
                    ball->showInfo();
                    Console::printSeparator();
                }
            }
            break;
        }
        case 5:
        {
            string sport;
            Console::enterTheSport();
            sport = Console::readFromKeyboard<string>();
            for (Ball* ball : balls)
            {
                if (ball->getSport() == sport)
                {
                    ball->showInfo();
                    Console::printSeparator();
                }
            }
            break;
        }
        }
        break;
    }
    case 4:
    {
        int option;
        Console::searchAccessories();
        option = Console::readFromKeyboard<int>();
        switch (option)
        {
        case 1:
        {
            long code;
            Console::enterProductCode();
            code = Console::readFromKeyboard<long>();
            for (Accessory* accessory : accessories)
            {
                if (accessory->productCode == code)
                {
                    accessory->showInfo();
                    Console::printSeparator();
                }
            }
            break;
        }
        
        case 2:
        {
            string brand;
            Console::enterTheBrand();
            brand = Console::readFromKeyboard<string>();
            for (Accessory* accessory : accessories)
            {
                if (accessory->brand == brand)
                {
                    accessory->showInfo();
                    Console::printSeparator();
                }
            }
            break;
        }
        case 3:
        {
            float price;
            Console::enterThePrice();
            price = Console::readFromKeyboard<float>();
            for (Accessory* accessory : accessories)
            {
                if (accessory->price <= price)
                {
                    accessory->showInfo();
                    Console::printSeparator();
                }
            }
            break;
        }
        case 4:
        {
            string color;
            Console::enterTheColor();
            color = Console::readFromKeyboard<string>();
            for (Accessory* accessory : accessories)
            {
                if (accessory->color == color)
                {
                    accessory->showInfo();
                    Console::printSeparator();
                }
            }
            break;
        }
        case 5:
        {
            string bodyPart;
            Console::enterBodyPart();
            bodyPart = Console::readFromKeyboard<string>();
            for (Accessory* accessory : accessories)
            {
                if (accessory->getBodyPart() == bodyPart)
                {
                    accessory->showInfo();
                    Console::printSeparator();
                }
            }
            break;
        }
        }
        break;
    }
    }
}
void Store::showFullInventory()
{
    int typeOption;
    do {
        Console::showProductsMenu();
        typeOption = Console::readFromKeyboard<int>();
        switch (typeOption)
        {
        case 0:
            break;
        case 1:
        {
            Console::showTitlesOfProducts("CLOTHING");
            for (Clothing* clothing : clothes)
            {
                clothing->showInfo();
            }
            break;
        }
        case 2:
        {
            Console::showTitlesOfProducts("SHOES");
            for (Shoe* shoe : shoes)
            {
                shoe->showInfo();
            }
            break;
        }
        case 3:
        {
            Console::showTitlesOfProducts("BALLS");
            for (Ball* ball : balls)
            {
                ball->showInfo();
            }
            break;
        }
        case 4:
        {
            Console::showTitlesOfProducts("ACCESSORIES");
            for (Accessory* accessory : accessories)
            {
                accessory->showInfo();
            }
            break;
        }
        case 5:
        {
            cout<< "Do you want to sort the products by price? (1 for yes, 2 for no): "<<endl;
            int option;
            cin>>option;
            if (option == 1)
            {
                QuickSort<Clothing>::sort(clothes);
                QuickSort<Shoe>::sort(shoes);
                QuickSort<Ball>::sort(balls);
                QuickSort<Accessory>::sort(accessories);
            }
            Console::showTitlesOfProducts("CLOTHING");
            for (Clothing* clothing : clothes)
            {
                clothing->showInfo();
            }
            Console::showTitlesOfProducts("SHOES");
            for (Shoe* shoe : shoes)
            {
                shoe->showInfo();
            }
            Console::showTitlesOfProducts("BALLS");
            for (Ball* ball : balls)
            {
                ball->showInfo();
            }
            Console::showTitlesOfProducts("ACCESSORIES");
            for (Accessory* accessory : accessories)
            {
                accessory->showInfo();
            }
            break;
        }
        default:
        {
            Console::invalid();
            system("Pause");
            break;
        }
        }
    } while (typeOption < 0 || typeOption > 5);
}
void Store::adjustSalariesAndBudgets()
{
    int numberOfEmployeesToFire, staffId, numberOfEmployeesToHire, option;
    if (Store::employeeCount >= Store::clientCount + 20) {
        Console::fireEmployee();
        option = Console::readFromKeyboard<int>();
        if (option != 1 && option != 2) {
            Console::invalid();
            return;
        }
        if (option == 1) {
            Console::numberOfFire();
            numberOfEmployeesToFire = Console::readFromKeyboard<int>();
            if (numberOfEmployeesToFire > Store::employeeCount || numberOfEmployeesToFire <= 0) {
                Console::invalid();
                return;
            }
            //now we have to fire the amount of employees chosen, lower the salaries of all other employees, and raise the budget of the owner.
            for (int i = 0; i < numberOfEmployeesToFire; i++) {
                Console::enterPersonId();
                staffId = Console::readFromKeyboard<int>();
                if (staffId < 1) {
                    Console::invalid();
                    return;
                }
                Staff* staffToFire = nullptr;
                for (Staff* staff : staffs)
                {
                    if (staff->getId() == staffId)
                    {
                        staffToFire = staff;
                    }
                }
                if (staffToFire == nullptr) {
                    Console::invalid();
                    return;
                }
                else {
                    //we have to lower the salaries of all other employees by 10% and raise the budget of the owner by 10%.
                    for (Staff* staff : staffs) {
                        if (staff->getId() != staffId) {
                            staff->setSalary(staff->getSalary() * 0.9);
                        }
                    }
                    owner->setBudget(owner->getBudget() * 1.1);
                    //now we have to remove the staff member from the staffs vector.
                    for (int i = 0; i < staffs.size(); i++) {
                        if (staffs[i]->getId() == staffId) {
                            staffs.erase(staffs.begin() + i);
                            employeeCount--;
                        }
                    }
                }
            }
        }
        else {
            //we have to lower the salaries of all employees by 10% and raise the budget of the owner by 10%.
            for (Staff* staff : staffs) {
                staff->setSalary(staff->getSalary() * 0.9);
            }
            owner->setBudget(owner->getBudget() * 1.1);
        }

    }
    else {
        if (Store::clientCount >= Store::employeeCount + 20) {
            Console::hireEmployee();
            option = Console::readFromKeyboard<int>();
            if (option != 1 && option != 2) {
                Console::invalid();
                return;
            }
            if (option == 1) {
                Console::numberOfHire();
                numberOfEmployeesToHire = Console::readFromKeyboard<int>();
                if (numberOfEmployeesToHire <= 0) {
                    Console::invalid();
                    return;
                }
                for (Staff* staff : staffs) {
                    staff->setSalary(staff->getSalary() * 1.1);

                }
                owner->setBudget(owner->getBudget() * 0.9);
                for (int i = 0; i < numberOfEmployeesToHire; i++) {
                    registerStaff();

                }
            }
            else {
                for (Staff* staff : staffs) {
                    staff->setSalary(staff->getSalary() * 1.1);

                }
                owner->setBudget(owner->getBudget() * 0.9);
            }
        }
    }
}
void Store::adjustPromotions()
{
    if (Store::clientCount >= 100) {
        for (Product* product : products) {
            product->setPrice(product->getPrice() * 0.99);
        }
    }
    else if (Store::clientCount >= 50 && Store::clientCount < 100) {
        for (Product* product : products) {
            product->setPrice(product->getPrice() * 0.98);
        }
    }
    else if (Store::clientCount >= 20 && Store::clientCount < 50) {
        for (Product* product : products) {
            product->setPrice(product->getPrice() * 0.97);
        }
    }
    else if (Store::clientCount >= 10 && Store::clientCount < 20) {
        for (Product* product : products) {
            product->setPrice(product->getPrice() * 0.95);
        }
    }
    else if (Store::clientCount >= 0 && Store::clientCount < 10) {
        for (Product* product : products) {
            product->setPrice(product->getPrice() * 0.9);
        }
    }
    else {
        Console::inactivePromotion();
    }
}
void Store::showTotalClientsAndEmployeesToMakeChanges()
{
    int option;
    do {
        Console::showClientsAndEmployeesMenu();
        option = Console::readFromKeyboard<int>();
        switch (option) {
        case 1:
            displayCount();
            system("Pause");
            break;
        case 2:
            adjustSalariesAndBudgets();
            system("Pause");
            break;
        case 3:
            adjustPromotions();
            system("Pause");
            break;
        case 0:
            Console::returnToPreviousMenu();
            break;
        default:
            Console::invalid();
            system("Pause");
        }
    } while (option != 0);
}
void Store::showMenu()
{
    int choice;
    do {
        Console::showMainMenu();
        choice = Console::readFromKeyboard<int>();
        switch (choice) {
        case 0:
            Console::completedProgram();
            break;
        case 1:
            registerClient();
            system("Pause");
            break;
        case 2:
            registerStaff();
            system("Pause");
            break;
        case 3:
            registerOwner();
            system("Pause");
            break;
        case 4:
            EditPersonInfo();
            system("Pause");
            break;
        case 5:
            showPersonInfo();
            system("Pause");
            break;
        case 6:
            showClientByType();
            system("Pause");
            break;
        case 7:
            purchaseMenu();
            system("Pause");
            break;
        case 8:
            registerAProduct();
            system("Pause");
            break;
        case 9:
            showProduct();
            system("Pause");
            break;
        case 10:
            raiseSalaryDependingOnNumberSold();
            system("Pause");
            break;
        case 11:
            searchAProduct();
            system("Pause");
            break;
        case 12:
            showFullInventory();
            system("Pause");
            break;
        case 13:
            showTotalClientsAndEmployeesToMakeChanges();
            system("Pause");
            break;
        default:
            Console::invalid();
            system("Pause");
        }
    } while (choice != 0);
}
void Store::run()
{
    LoadData* ptr = new TxtLocalLoader();
    clients = ptr->vecClient();
    staffs = ptr->vecStaff();
    showMenu();
}
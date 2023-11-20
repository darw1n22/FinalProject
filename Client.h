#pragma once
#include "Person.h"

class Client :public Person
{
private:
    bool isPremium;
    float purchases;
    float totalPurchases;
    int numPurchases;
    //Person* person;
public:
    /*
    Client(long id, long phone, string& name, string& lastname, string& email, string& address, int gender, int age, bool isPremium, float purchases, float totalPurchases, int numPurchases)
        :Person(id, name, lastname, gender, email, address, phone, age), isPremium(isPremium), purchases(purchases), totalPurchases(totalPurchases), numPurchases(numPurchases) {}
    */
    Client(long id, string name, string lastname, int gender, string email, string address, long phone, int age, bool isPremium, float purchases, float totalPurchases, int numPurchases);
    ~Client();
    bool getIsPremium();
    void setIsPremium(bool premium);
    float getPurchases();
    void setPurchases(float numPurchases);
    float getTotalPurchases();
    void setTotalPurchases(float total);
    int getNumPurchases();
    void setNumPurchases(int newnumPurchases);
    void displayInfo() override {
        Person::displayInfo();
        cout << "Is Premium: " << (isPremium ? "Yes" : "No") << endl;
        cout << "Purchases: " << purchases << endl;
        cout << "Total Purchases: " << totalPurchases << endl;
        cout << "Number of purchases: " << numPurchases << endl;
    }
};



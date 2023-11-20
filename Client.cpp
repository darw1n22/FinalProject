#include "pch.h"
#include "Client.h"

Client::Client(long id, string name, string lastname, int gender, string email, string address, long phone, int age, bool isPremium, float purchases, float totalPurchases, int numPurchases)
    :Person(id,name,lastname,gender,email,address,phone,age)
{
    this->isPremium = isPremium;
    this->purchases = purchases;
    this->totalPurchases = totalPurchases;
    this->numPurchases = numPurchases;
}

Client::~Client()
{
}

bool Client::getIsPremium()
{
    return isPremium;
}

void Client::setIsPremium(bool premium)
{
    isPremium = premium;
}

float Client::getPurchases()
{
    return purchases;
}

void Client::setPurchases(float numPurchases)
{
    purchases = numPurchases;
}

float Client::getTotalPurchases()
{
    return totalPurchases;
}

void Client::setTotalPurchases(float total)
{
    totalPurchases = total;
}

int Client::getNumPurchases()
{
    return numPurchases;
}

void Client::setNumPurchases(int newnumPurchases)
{
    numPurchases = newnumPurchases;
}

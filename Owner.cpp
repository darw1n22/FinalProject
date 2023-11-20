#include "pch.h"
#include "Owner.h"

Owner::Owner(long id, string name, string lastname, int gender, string email, string address, long phone, int age, int budget)
    :Person(id,name,lastname,gender,email,address,phone,age)
{
    this->budget = budget;
}

Owner::~Owner()
{
}

int Owner::getBudget()
{
    return budget;
}

void Owner::setBudget(int newBudget)
{
    int budget = 0;
    if (newBudget >= 0) {
        budget = newBudget;
    }
    else {
        cout << "Your new budget must be greater than or equal to zero!" << endl;
    }
}
#pragma once
#include "Client.h"
#include "Staff.h"
#include "Owner.h"
#include <vector>
#include <iostream>

using namespace std;

class LoadData
{
public:
	~LoadData();
	LoadData();
	virtual vector<Client*> vecClient() = 0;
	virtual vector<Staff*> vecStaff() = 0;
	virtual vector<Owner*> vecOwner() = 0;

};

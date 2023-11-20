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
	virtual vector<Client*> vecClient();
	virtual vector<Staff*> vecStaff();
	virtual vector<Owner*> vecOwner();

};

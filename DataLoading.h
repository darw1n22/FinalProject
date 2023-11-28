#pragma once
#include "Client.h"
#include "Staff.h"
#include "Owner.h"
#include "Accessory.h"
#include "Ball.h"
#include <vector>
#include <iostream>

using namespace std;

class DataLoading
{
public:
	~DataLoading();
	DataLoading();
	virtual vector<Client*> vecClient() = 0;
	virtual vector<Staff*> vecStaff() = 0;
	virtual vector<Owner*> vecOwner() = 0;
	virtual vector<Accessory*> vecAccesory() = 0;
	virtual vector<Ball*> vecBall() = 0;

};

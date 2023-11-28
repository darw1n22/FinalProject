#pragma once
#include "Client.h"
#include "Staff.h"
#include "Owner.h"
#include "Clothing.h"
#include "Shoe.h"
#include "DataLoader.h"
#include <vector>
#include <iostream>	
#include <fstream>
using namespace std;
class TxtLocalLoader : public DataLoader
{
public:
	~TxtLocalLoader();
	TxtLocalLoader();

	vector<Client*> vecClient();
	vector<Staff*> vecStaff();
	vector<Owner*> vecOwner();
	vector<Ball*> vecBall();
	vector<Clothing*> vecClothing();
	vector<Shoe*> vecShoe();
	vector<Accessory*> vecAccesory();
};

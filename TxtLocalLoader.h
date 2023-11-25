#pragma once
#include "Client.h"
#include "Staff.h"
#include "Owner.h"
#include "LoadData.h"
#include <vector>
#include <iostream>	
#include <fstream>
using namespace std;
class TxtLocalLoader : public LoadData
{
public:
	~TxtLocalLoader();
	TxtLocalLoader();

	vector<Client*> vecClient();
	vector<Staff*> vecStaff();
	vector<Owner*> vecOwner();
};

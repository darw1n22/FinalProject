#pragma once
#include "Console.h"

class StoreConsole : public Console
{
public:
	/*StoreConsole();
	~StoreConsole();*/
	void showMainMenu() override;
	int selectOption() override;
	void completedProgram() override;
	void invalidSelection() override;
};


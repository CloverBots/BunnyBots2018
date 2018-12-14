#pragma once

#include "WPILib.h"
#include "../CommandBase.h"

class CubeConveyorCMD : public CommandBase
{
private:
bool a = false;
public:
	CubeConveyorCMD();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

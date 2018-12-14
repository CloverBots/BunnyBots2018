#pragma once

#include "WPILib.h"

#include "../CommandBase.h"

class BallConveyorCMD : public CommandBase
{
private:
	int start_time = 0;
	int end_time = 0;
public:
	BallConveyorCMD();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

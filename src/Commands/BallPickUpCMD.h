#pragma once

#include "WPILib.h"
#include "../CommandBase.h"

class BallPickUpCMD : public CommandBase
{
private:
public:
	BallPickUpCMD();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

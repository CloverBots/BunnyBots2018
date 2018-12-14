#pragma once

#include "../CommandBase.h"

class CubePickUpCMD : public CommandBase
{
private:
public:
	CubePickUpCMD();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#ifndef BallConveyorCMD_H
#define BallConveyorCMD_H
#include "WPILib.h"

#include "../CommandBase.h"

class BallConveyorCMD : public CommandBase {
private:
	int start_time;
	int end_time;
public:
	BallConveyorCMD();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // BallConveyorCMD_H

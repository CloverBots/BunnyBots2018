#ifndef BallConveyorCMD_H
#define BallConveyorCMD_H
#include "WPILib.h"

#include "../CommandBase.h"

class BallConveyorCMD : public CommandBase {
private:
	double speed;
public:
	BallConveyorCMD(double speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // BallConveyorCMD_H

#ifndef CubeConveyorCMD_H
#define CubeConveyorCMD_H
#include "WPILib.h"
#include "../CommandBase.h"

class CubeConveyorCMD : public CommandBase {
private:
	double speed;
public:
	CubeConveyorCMD(double speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // CubeConveyorCMD_H

#ifndef BallPickUpCMD_H
#define BallPickUpCMD_H
#include "WPILib.h"

#include "../CommandBase.h"

class BallPickUpCMD : public CommandBase {
private:
public:
	BallPickUpCMD();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // BallPickUpCMD_H

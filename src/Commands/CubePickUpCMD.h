#ifndef CubePickUpCMD_H
#define CubePickUpCMD_H

#include "../CommandBase.h"

class CubePickUpCMD : public CommandBase {
private:
	double speed;
public:
	CubePickUpCMD(double speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // CubePickUpCMD_H

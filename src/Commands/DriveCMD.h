#ifndef DriveCMD_H
#define DriveCMD_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveCMD : public CommandBase {
public:
	DriveCMD();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveCMD_H

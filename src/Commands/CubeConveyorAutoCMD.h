/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Command.h>
#include "../CommandBase.h"

class CubeConveyorAutoCMD : public frc::Command {
private:

	bool latch1 = false;
	bool latch2 = false;
	long long unsigned int start_time = 0;
	long long unsigned int end_time = 0;
public:
	CubeConveyorAutoCMD();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};


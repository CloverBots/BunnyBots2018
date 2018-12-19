/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Command.h>
#include "../CommandBase.h"
#include <chrono>

class CubePickUpAutoCMD : public frc::Command
{
private:
	bool grab;
	double ball;
	double cube;
	std::chrono::system_clock::time_point start_time;
	int start;
	int end;
	std::chrono::system_clock::time_point end_time;
	bool latch = false;
	bool latch2 = false;
public:
	CubePickUpAutoCMD(bool grab, double ball, double cube);
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};


/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "BallSortAutoCMD.h"

#include "../CommandBase.h"
#include <iostream>

BallSortAutoCMD::BallSortAutoCMD() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::BallSortSubsystem.get());
}

// Called just before this Command runs the first time
void BallSortAutoCMD::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void BallSortAutoCMD::Execute() {
	CommandBase::BallSortSubsystem->UpdateSensor();
	if(CommandBase::BallSortSubsystem->IsRed() || CommandBase::BallSortSubsystem->IsBlue())
	{
		std::cout << "on" << std::endl;
		CommandBase::BallSortSubsystem->SetSolenoid(Relay::Value::kReverse);
		CommandBase::oi->start_time = std::chrono::high_resolution_clock::now();
		CommandBase::oi->start = 1;
		CommandBase::oi->total_ball_count++;
	}
	else
	{
		CommandBase::oi->end_time = std::chrono::high_resolution_clock::now();
		if(CommandBase::oi->start != 0)
		{
			//std::cout << (double)(CommandBase::oi->start_time - CommandBase::oi->end_time)/CLOCKS_PER_SEC << std::endl;
		}
		if(std::chrono::duration_cast<std::chrono::seconds>(CommandBase::oi->end_time - CommandBase::oi->start_time).count() >= -.5)
		{
			std::cout << "off" << std::endl;
			CommandBase::oi->start = 0;
			CommandBase::BallSortSubsystem->SetSolenoid(Relay::Value::kForward);
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool BallSortAutoCMD::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void BallSortAutoCMD::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BallSortAutoCMD::Interrupted() {

}

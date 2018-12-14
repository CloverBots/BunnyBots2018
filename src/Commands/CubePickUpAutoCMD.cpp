/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "CubePickUpAutoCMD.h"

CubePickUpAutoCMD::CubePickUpAutoCMD(bool grab, double ball, double cube) : grab(grab), ball(ball), cube(cube)
{
	Requires(CommandBase::CubePickUpSubsystem.get());
	Requires(CommandBase::BallPickUpSubsystem.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void CubePickUpAutoCMD::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void CubePickUpAutoCMD::Execute()
{
	if(grab)
	{
		CommandBase::CubePickUpSubsystem->Grab(DoubleSolenoid::Value::kForward);
	}
	else
	{
		CommandBase::CubePickUpSubsystem->Grab(DoubleSolenoid::Value::kForward);
	}


	CommandBase::BallPickUpSubsystem->SetSpeed(ball);
	CommandBase::CubePickUpSubsystem->SetSpeed(cube);
}

// Make this return true when this Command no longer needs to run execute()
bool CubePickUpAutoCMD::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void CubePickUpAutoCMD::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CubePickUpAutoCMD::Interrupted()
{

}

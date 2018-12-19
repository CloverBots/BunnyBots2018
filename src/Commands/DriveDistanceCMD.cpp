/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <Commands/DriveDistanceCMD.h>
#include "../CommandBase.h"
#include <iostream>

DriveDistanceCMD::DriveDistanceCMD(double distance) : distance(distance)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void DriveDistanceCMD::Initialize()
{
	//CommandBase::driveSubsystem->ResetDrive();
	CommandBase::driveSubsystem->Shift(DoubleSolenoid::Value::kForward);
	CommandBase::driveSubsystem->ResetGyro();
	//CommandBase::driveSubsystem->SetDrive(true, distance);
	CommandBase::driveSubsystem->SetDriveRotate(true, CommandBase::driveSubsystem->GetGyroAngle());

}

// Called repeatedly when this Command is scheduled to run
void DriveDistanceCMD::Execute()
{
	//std::cout << CommandBase::driveSubsystem->GetGyroAngle() << std::endl;

	CommandBase::driveSubsystem->PIDDrive(distance);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveDistanceCMD::IsFinished() {
	//if(CommandBase::driveSubsystem->OnTarget())
	//{
	//	CommandBase::driveSubsystem->SetDrivePIDEnabled(false);
	//	CommandBase::driveSubsystem->ResetDrive();
	//	CommandBase::driveSubsystem->SetDriveRotatePIDEnabled(false);
	//	CommandBase::driveSubsystem->ResetGyro();
	//	return true;
	//}
	//else
	//{
		return false;
	//}
}

// Called once after isFinished returns true
void DriveDistanceCMD::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveDistanceCMD::Interrupted()
{

}

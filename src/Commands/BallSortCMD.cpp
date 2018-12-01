/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "BallSortCMD.h"
#include "../CommandBase.h"

BallSortCMD::BallSortCMD()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::BallSortSubsystem.get());
}

// Called just before this Command runs the first time
void BallSortCMD::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void BallSortCMD::Execute()
{
	CommandBase::BallSortSubsystem->UpdateSensor();
	if(CommandBase::oi->GetTeam() == DriverStation::Alliance::kRed)
	{
		if(CommandBase::BallSortSubsystem->IsRed())
		{
			if(CommandBase::oi->start_time == 0)
			{
				CommandBase::BallSortSubsystem->SetSolenoid(Relay::Value::kForward);
				CommandBase::oi->start_time = clock();
				CommandBase::oi->total_ball_count++;
				CommandBase::oi->in_cube_ball_count++;
			}
			else
			{
				CommandBase::oi->end_time = clock();
				if((CommandBase::oi->end_time - CommandBase::oi->start_time)/CLOCKS_PER_SEC >= .25)
				{
					CommandBase::BallSortSubsystem->SetSolenoid(Relay::Value::kReverse);
				}
			}
		}
		else
		{
			CommandBase::BallSortSubsystem->SetSolenoid(Relay::Value::kReverse);
		}
	}
	else if(CommandBase::oi->GetTeam() == DriverStation::Alliance::kBlue)
	{
		if(CommandBase::BallSortSubsystem->IsBlue())
		{
			if(CommandBase::oi->start_time == 0)
			{
				CommandBase::BallSortSubsystem->SetSolenoid(Relay::Value::kForward);
				CommandBase::oi->start_time = clock();
				CommandBase::oi->in_cube_ball_count++;
			}
			else
			{
				CommandBase::oi->end_time = clock();
				if((CommandBase::oi->end_time - CommandBase::oi->start_time)/CLOCKS_PER_SEC >= .25)
				{
					CommandBase::BallSortSubsystem->SetSolenoid(Relay::Value::kReverse);
					CommandBase::oi->start_time = 0;
				}
			}
		}
		else
		{
			CommandBase::BallSortSubsystem->SetSolenoid(Relay::Value::kReverse);
		}
	}
	else
	{
		CommandBase::BallSortSubsystem->SetSolenoid(Relay::Value::kReverse);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool BallSortCMD::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void BallSortCMD::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BallSortCMD::Interrupted()
{

}

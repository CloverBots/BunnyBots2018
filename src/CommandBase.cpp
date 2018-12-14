#include "CommandBase.h"

#include <Commands/Scheduler.h>
#include <iostream>
#include "Subsystems/DriveSub.h"

// Initialize a single static instance of all of your subsystems. The following
// line should be repeated for each subsystem in the project.

std::unique_ptr<OI> CommandBase::oi;
std::unique_ptr<DriveSub> CommandBase::driveSubsystem;
std::unique_ptr<BallConveyor> CommandBase::BallConveyorSubsystem;
std::unique_ptr<BallPickUp> CommandBase::BallPickUpSubsystem;
std::unique_ptr<CubeConveyor> CommandBase::CubeConveyorSubsystem;
std::unique_ptr<CubePickUp> CommandBase::CubePickUpSubsystem;
std::unique_ptr<BallSort> CommandBase::BallSortSubsystem;

CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {
}

void CommandBase::Init()
{
	driveSubsystem.reset(new DriveSub);
	BallConveyorSubsystem.reset(new BallConveyor);
	CubeConveyorSubsystem.reset(new CubeConveyor);
	CubePickUpSubsystem.reset(new CubePickUp);
	BallPickUpSubsystem.reset(new BallPickUp);
	BallSortSubsystem.reset(new BallSort);
	oi.reset(new OI);
}


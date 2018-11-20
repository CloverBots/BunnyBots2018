#include "CommandBase.h"

#include <Commands/Scheduler.h>

#include "Subsystems/DriveSub.h"

// Initialize a single static instance of all of your subsystems. The following
// line should be repeated for each subsystem in the project.

std::unique_ptr<DriveSub> CommandBase::driveSubsystem =
		std::make_unique<DriveSub>();
std::unique_ptr<BallConveyor> CommandBase::BallConveyorSubsystem =
		std::make_unique<BallConveyor>();
std::unique_ptr<BallPickUp> CommandBase::BallPickUpSubsystem =
		std::make_unique<BallPickUp>();
std::unique_ptr<CubeConveyor> CommandBase::CubeConveyorSubsystem =
		std::make_unique<CubeConveyor>();
std::unique_ptr<CubePickUp> CommandBase::CubePickUpSubsystem =
		std::make_unique<CubePickUp>();

std::unique_ptr<OI> CommandBase::oi = std::make_unique<OI>();

CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {

}

#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <memory>
#include <string>
#include <WPILib.h>
#include <Commands/Command.h>

#include "OI.h"
#include "Subsystems/DriveSub.h"
#include "Subsystems/BallConveyor.h"
#include "Subsystems/BallPickUp.h"
#include "Subsystems/CubeConveyor.h"
#include "Subsystems/CubePickUp.h"
#include "Subsystems/BallSort.h"


/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use
 * CommandBase::exampleSubsystem
 */
class CommandBase: public frc::Command {
public:
	CommandBase(const std::string& name);
	CommandBase() = default;
	static void Init();
	// Create a single static instance of all of your subsystems
	static std::unique_ptr<OI> oi;
	static std::unique_ptr<DriveSub> driveSubsystem;
	static std::unique_ptr<BallConveyor> BallConveyorSubsystem;
	static std::unique_ptr<BallPickUp> BallPickUpSubsystem;
	static std::unique_ptr<CubeConveyor> CubeConveyorSubsystem;
	static std::unique_ptr<CubePickUp> CubePickUpSubsystem;
	static std::unique_ptr<BallSort> BallSortSubsystem;
};
#endif  // COMMAND_BASE_H

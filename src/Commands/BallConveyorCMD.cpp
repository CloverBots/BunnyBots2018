#include "BallConveyorCMD.h"

BallConveyorCMD::BallConveyorCMD(double speed) : speed(speed){
	Requires(CommandBase::BallConveyorSubsystem.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void BallConveyorCMD::Initialize() {
	CommandBase::BallConveyorSubsystem->SetSpeed(0);
}

// Called repeatedly when this Command is scheduled to run
void BallConveyorCMD::Execute() {
	CommandBase::BallConveyorSubsystem->SetSpeed(speed);
}

// Make this return true when this Command no longer needs to run execute()
bool BallConveyorCMD::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void BallConveyorCMD::End() {
	CommandBase::BallConveyorSubsystem->SetSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BallConveyorCMD::Interrupted() {

}

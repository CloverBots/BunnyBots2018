#include "CubeConveyorCMD.h"

CubeConveyorCMD::CubeConveyorCMD(double speed) : speed(speed){
	Requires(CommandBase::CubeConveyorSubsystem.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void CubeConveyorCMD::Initialize() {
	CommandBase::CubeConveyorSubsystem->SetSpeed(0);
}

// Called repeatedly when this Command is scheduled to run
void CubeConveyorCMD::Execute() {
	CommandBase::CubeConveyorSubsystem->SetSpeed(speed);
}

// Make this return true when this Command no longer needs to run execute()
bool CubeConveyorCMD::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void CubeConveyorCMD::End() {
	CommandBase::CubeConveyorSubsystem->SetSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CubeConveyorCMD::Interrupted() {

}

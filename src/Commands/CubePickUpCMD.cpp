#include "CubePickUpCMD.h"

CubePickUpCMD::CubePickUpCMD(double speed) : speed(speed){
	Requires(CommandBase::CubePickUpSubsystem.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void CubePickUpCMD::Initialize() {
	CommandBase::CubePickUpSubsystem->SetSpeed(0);
}

// Called repeatedly when this Command is scheduled to run
void CubePickUpCMD::Execute() {
	CommandBase::CubePickUpSubsystem->SetSpeed(speed);
}

// Make this return true when this Command no longer needs to run execute()
bool CubePickUpCMD::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void CubePickUpCMD::End() {
	CommandBase::CubePickUpSubsystem->SetSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CubePickUpCMD::Interrupted() {

}

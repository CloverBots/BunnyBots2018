#include "CubeConveyor.h"
#include "../RobotMap.h"
#include <ctre/Phoenix.h>
#include "WPILib.h"
#include "Commands/CubeConveyorCMD.h"

CubeConveyor::CubeConveyor() : Subsystem("CubeConveyorSubsystem") {
	Cube_Conveyor_Front = new WPI_TalonSRX(RobotMap::Cube_Conveyor_Left);
	Cube_Conveyor_Back = new WPI_TalonSRX(RobotMap::Cube_Conveyor_Right);
	Front_Switch = new DigitalInput(0);
	Back_Switch = new DigitalInput(1);
}

void CubeConveyor::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new CubeConveyorCMD());
}

void CubeConveyor::SetFront(double speed)
{
	Cube_Conveyor_Front->Set(speed);
}

void CubeConveyor::SetBack(double speed)
{
	Cube_Conveyor_Back->Set(speed);
}

bool CubeConveyor::GetBackSwitch()
{
	return Back_Switch->Get();
}

bool CubeConveyor::GetFrontSwitch()
{
	return Front_Switch->Get();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

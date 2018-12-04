#include "CubeConveyor.h"
#include "../RobotMap.h"
#include <ctre/Phoenix.h>
#include "WPILib.h"
#include "Commands/CubeConveyorCMD.h"

CubeConveyor::CubeConveyor() : Subsystem("CubeConveyorSubsystem")
{
	Cube_Conveyor_Front_1 = new WPI_TalonSRX(RobotMap::Cube_Conveyor_Left_1);
	Cube_Conveyor_Back_1 = new WPI_TalonSRX(RobotMap::Cube_Conveyor_Right_1);
	Cube_Conveyor_Front_2 = new WPI_TalonSRX(RobotMap::Cube_Conveyor_Left_2);
	Cube_Conveyor_Back_2 = new WPI_TalonSRX(RobotMap::Cube_Conveyor_Right_2);
	Ball_Hopper_Motor = new WPI_TalonSRX(RobotMap::Ball_Hopper_Motor);
	Ball_Hopper_Motor->ConfigSelectedFeedbackSensor(phoenix::motorcontrol::FeedbackDevice::QuadEncoder, 0, 0);
	Ball_Hopper_Motor->GetSensorCollection().SetQuadraturePosition(0, 10);
	Ball_Hopper_Source = new EncPIDSource(Ball_Hopper_Motor);
	Ball_Hopper_Controller = new PIDController(P, I, D, Ball_Hopper_Source, Ball_Hopper_Motor);
	Ball_Hopper_Servo = new Servo(1);
	Front_Switch = new DigitalInput(0);
	Back_Switch = new DigitalInput(1);
}

void CubeConveyor::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new CubeConveyorCMD());
}

void CubeConveyor::SetServo(double angle)
{
	Ball_Hopper_Servo->SetAngle(angle);
}

void CubeConveyor::SetHopper(double speed)
{
	Ball_Hopper_Motor->Set(speed);
}

void CubeConveyor::SetEnabled(bool enabled)
{
	Ball_Hopper_Controller->SetEnabled(enabled);
}
void CubeConveyor::SetSetPoint(double setpoint)
{
	Ball_Hopper_Controller->SetSetpoint(setpoint);
}

double CubeConveyor::GetSetPoint()
{
	return Ball_Hopper_Controller->GetSetpoint();
}

bool CubeConveyor::OnTarget()
{
	return Ball_Hopper_Controller->OnTarget();
}

void CubeConveyor::SetFront(double speed)
{
	Cube_Conveyor_Front_1->Set(speed);
	Cube_Conveyor_Front_2->Set(-speed);
}

void CubeConveyor::SetBack(double speed)
{
	Cube_Conveyor_Back_1->Set(speed);
	Cube_Conveyor_Back_2->Set(-speed);
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

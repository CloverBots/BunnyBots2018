#include "DriveSub.h"
#include "../RobotMap.h"
#include <WPILib.h>
#include "DriveSub.h"
#include "Commands/DriveCMD.h"
#include <iostream>

DriveSub::DriveSub() : Subsystem("DriveSub")
{
	Front_Left_Motor = new WPI_TalonSRX(RobotMap::Front_Left_Motor);
	Front_Right_Motor = new WPI_TalonSRX(RobotMap::Front_Right_Motor);
	Middle_Left_Motor = new WPI_TalonSRX(RobotMap::Middle_Left_Motor);
	Middle_Right_Motor = new WPI_TalonSRX(RobotMap::Middle_Right_Motor);
	Back_Left_Motor = new WPI_TalonSRX(RobotMap::Back_Left_Motor);
	Back_Right_Motor = new WPI_TalonSRX(RobotMap::Back_Right_Motor);

	m_gyro = new ADXRS450_Gyro(SPI::kOnboardCS0);

	Middle_Right_Motor->ConfigSelectedFeedbackSensor(phoenix::motorcontrol::FeedbackDevice::QuadEncoder, 0, 0);
	Middle_Left_Motor->ConfigSelectedFeedbackSensor(phoenix::motorcontrol::FeedbackDevice::QuadEncoder, 0, 0);
	Middle_Right_Motor->GetSensorCollection().SetQuadraturePosition(0, 10);
	Middle_Left_Motor->GetSensorCollection().SetQuadraturePosition(0, 10);


	Front_Right_Motor->SetInverted(true);
	Middle_Right_Motor->SetInverted(true);
	Back_Right_Motor->SetInverted(true);
	Gear_Box = new DoubleSolenoid(1, 0);

	DriveSource = new Enc2PIDSource(Middle_Right_Motor, Middle_Left_Motor);
	DriveOutput = new PIDValOutput();
	RotateOutput = new PIDValOutput();
	DrivePID = new PIDController(m_DriveP, m_DriveI, m_DriveD, DriveSource, DriveOutput);
	DriveRotatePID = new PIDController(m_RotateP, m_RotateI, m_RotateD, m_gyro, RotateOutput);
	DriveRotatePID->SetAbsoluteTolerance(0);
}

void DriveSub::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new DriveCMD());
}

void DriveSub::Drive(double speed, double turn)
{
	SmartDashboard::PutNumber("Gyro", m_gyro->PIDGet());
	Front_Left_Motor->Set(speed - turn);
	Front_Right_Motor->Set(speed + turn);
	Middle_Left_Motor->Set(speed - turn);
	Middle_Right_Motor->Set(speed + turn);
	Back_Left_Motor->Set(speed - turn);
	Back_Right_Motor->Set(speed + turn);
}

void DriveSub::Shift(DoubleSolenoid::Value value)
{
	Gear_Box->Set(value);
}

double DriveSub::GetDriveOutput()
{
	return DriveOutput->GetValue();
}

double DriveSub::GetRotateOutput()
{
	return RotateOutput->GetValue();
}

void DriveSub::ResetGyro()
{
	m_gyro->Reset();
}

void DriveSub::ResetDrive()
{
	DriveSource->Reset();
}

double DriveSub::GetGyroAngle()
{
	return m_gyro->GetAngle();
}

void DriveSub::PIDDrive(double speed)
{
	speed = -speed;
	SmartDashboard::PutNumber("Gyro", m_gyro->PIDGet());
	if(m_gyro->PIDGet() > max)
	{
		max = m_gyro->PIDGet();
	}
	if(m_gyro->PIDGet() < min)
	{
		min = m_gyro->PIDGet();
	}

	//std::cout << "MAX: " << max << "   MIN: " << min << std::endl;
	Front_Left_Motor->Set(speed - GetRotateOutput());
	Front_Right_Motor->Set(speed + GetRotateOutput());
	Middle_Left_Motor->Set(speed - GetRotateOutput());
	Middle_Right_Motor->Set(speed + GetRotateOutput());
	Back_Left_Motor->Set(speed - GetRotateOutput());
	Back_Right_Motor->Set(speed + GetRotateOutput());
}

void DriveSub::SetDrivePIDEnabled(bool enabled)
{

	DrivePID->SetSetpoint(0.0f);
	Drive(0, 0);
	DrivePID->Reset();

	if (enabled)
	{
		DrivePID->Enable();
	}
}

void DriveSub::SetDriveRotatePIDEnabled(bool enabled)
{
	DriveRotatePID->SetSetpoint(0.0f);
	Drive(0, 0);
	DriveRotatePID->Reset();

	if (enabled)
		DriveRotatePID->Enable();
}

void DriveSub::SetDrive(bool enabled, double setpoint)
{
	SetDrivePIDEnabled(enabled);
	DrivePID->SetSetpoint(setpoint);
}

bool DriveSub::OnTarget()
{
	return DrivePID->OnTarget();
}

void DriveSub::SetDriveRotate(bool enabled, double setpoint)
{
	SetDriveRotatePIDEnabled(enabled);
	DriveRotatePID->SetSetpoint(setpoint);
}

void DriveSub::UpdateFromSmartDashboard()
{
	SmartDashboard::PutNumber("Gyro", m_gyro->GetAngle());
}

double DriveSub::GetDistance()
{
	DistanceRight += (Middle_Right_Motor->GetSelectedSensorPosition(0) / 54.3702 / 21.6 - DistanceOldRight);
	DistanceOldRight = DistanceRight;
	DistanceLeft += (Back_Left_Motor->GetSelectedSensorPosition(0) / 54.3702 / 21.6 - DistanceOldLeft);
	DistanceOldLeft = DistanceLeft;
	return (DistanceRight + DistanceLeft) / 2;
}

void DriveSub::DisableAllPID()
{
	DrivePID->Disable();
	DriveRotatePID->Disable();
}

void DriveSub::Calibrate()
{
	m_gyro->Calibrate();
}
// Put methods for controlling this subsystem
// here. Call these from Commands.

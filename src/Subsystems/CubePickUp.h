#pragma once

#include <WPILib.h>
#include <Commands/Subsystem.h>
#include <ctre/Phoenix.h>

class CubePickUp : public Subsystem
{
private:
	WPI_TalonSRX* Cube_Pick_Up_Left;
	WPI_TalonSRX* Cube_Pick_Up_Right;
	DigitalInput* Grabber_Sensor;
	DoubleSolenoid* Grabber;
public:
	CubePickUp();
	void SetSpeed(double speed);
	bool GetSensor();
	void Grab(DoubleSolenoid::Value value);
	void InitDefaultCommand();
};

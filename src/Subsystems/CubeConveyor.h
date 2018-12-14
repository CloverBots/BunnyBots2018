#pragma once

#include <Commands/Subsystem.h>
#include <WPILib.h>
#include <ctre/Phoenix.h>
#include "../EncPIDSource.h"

class CubeConveyor : public Subsystem
{
private:

	const double P = 0;
	const double I = 0;
	const double D = 0;

	WPI_TalonSRX* Cube_Conveyor_Front_1;
	WPI_TalonSRX* Cube_Conveyor_Back_1;
	WPI_TalonSRX* Cube_Conveyor_Front_2;
	WPI_TalonSRX* Cube_Conveyor_Back_2;

	WPI_VictorSPX* Ball_Hopper_Motor;
	EncPIDSource* Ball_Hopper_Source;
	PIDController* Ball_Hopper_Controller;

	DoubleSolenoid* Ball_Hopper_Solenoid;

	DigitalInput* Front_Switch;
	DigitalInput* Back_Switch;
	DigitalInput* HopperSwitch;

public:
	CubeConveyor();
	void SetSoldenoid(DoubleSolenoid::Value value);
	void SetHopper(double speed);
	void SetEnabled(bool enabled);
	void SetSetPoint(double setpoint);
	bool GetSwitch();
	double GetSetPoint();
	bool OnTarget();
	void SetFront(double speed);
	void SetBack(double speed);
	bool GetFrontSwitch();
	bool GetBackSwitch();
	void InitDefaultCommand();
};

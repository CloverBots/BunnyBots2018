#ifndef CubeConveyor_H
#define CubeConveyor_H

#include <Commands/Subsystem.h>
#include <WPILib.h>
#include <ctre/Phoenix.h>
#include "../EncPIDSource.h"

class CubeConveyor : public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	const double P = 0;
	const double I = 0;
	const double D = 0;
	WPI_TalonSRX* Cube_Conveyor_Front_1;
	WPI_TalonSRX* Cube_Conveyor_Back_1;
	WPI_TalonSRX* Cube_Conveyor_Front_2;
	WPI_TalonSRX* Cube_Conveyor_Back_2;

	WPI_TalonSRX* Ball_Hopper_Motor;
	EncPIDSource* Ball_Hopper_Source;
	PIDController* Ball_Hopper_Controller;

	Servo* Ball_Hopper_Servo;

	DigitalInput* Front_Switch;
	DigitalInput* Back_Switch;

public:
	CubeConveyor();
	void SetServo(double angle);
	void SetHopper(double speed);
	void SetEnabled(bool enabled);
	void SetSetPoint(double setpoint);
	double GetSetPoint();
	bool OnTarget();
	void SetFront(double speed);
	void SetBack(double speed);
	bool GetFrontSwitch();
	bool GetBackSwitch();
	void InitDefaultCommand();
};

#endif  // CubeConveyor_H

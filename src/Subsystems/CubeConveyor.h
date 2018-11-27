#ifndef CubeConveyor_H
#define CubeConveyor_H

#include <Commands/Subsystem.h>
#include <WPILib.h>
#include <ctre/Phoenix.h>

class CubeConveyor : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	WPI_TalonSRX* Cube_Conveyor_Front;
	WPI_TalonSRX* Cube_Conveyor_Back;
	DigitalInput* Front_Switch;
	DigitalInput* Back_Switch;

public:
	CubeConveyor();
	void SetFront(double speed);
	void SetBack(double speed);
	bool GetFrontSwitch();
	bool GetBackSwitch();
	void InitDefaultCommand();
};

#endif  // CubeConveyor_H

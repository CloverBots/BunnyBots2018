#ifndef CubeConveyor_H
#define CubeConveyor_H

#include <Commands/Subsystem.h>
#include <WPILib.h>

class CubeConveyor : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Talon* Cube_Conveyor_Left;
	Talon* Cube_Conveyor_Right;

public:
	CubeConveyor();
	void SetSpeed(double speed);
	void InitDefaultCommand();
};

#endif  // CubeConveyor_H

#ifndef CubePickUp_H
#define CubePickUp_H
#include <WPILib.h>
#include <Commands/Subsystem.h>

class CubePickUp : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Talon* Cube_Pick_Up_Left;
	Talon* Cube_Pick_Up_Right;
public:
	CubePickUp();
	void SetSpeed(double speed);
	void InitDefaultCommand();
};

#endif  // CubePickUp_H

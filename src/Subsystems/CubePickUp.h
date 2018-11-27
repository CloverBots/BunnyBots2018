#ifndef CubePickUp_H
#define CubePickUp_H
#include <WPILib.h>
#include <Commands/Subsystem.h>
#include <ctre/Phoenix.h>

class CubePickUp : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	WPI_TalonSRX* Cube_Pick_Up_Left;
	WPI_TalonSRX* Cube_Pick_Up_Right;

	DoubleSolenoid* Grabber;
public:
	CubePickUp();
	void SetSpeed(double speed);
	void Grab(DoubleSolenoid::Value value);
	void InitDefaultCommand();
};

#endif  // CubePickUp_H

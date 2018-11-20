#ifndef DriveSub_H
#define DriveSub_H
#include <WPILib.h>
#include <Commands/Subsystem.h>

class DriveSub : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Talon* Front_Left_Motor;
	Talon* Front_Right_Motor;
	Talon* Middle_Left_Motor;
	Talon* Middle_Right_Motor;
	Talon* Back_Left_Motor;
	Talon* Back_Right_Motor;
	DoubleSolenoid* Gear_Box;
public:
	DriveSub();
	void Drive(double speed, double turn);
	void Shift(DoubleSolenoid::Value value);
	void InitDefaultCommand();
};

#endif  // DriveSub_H

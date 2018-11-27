#ifndef DriveSub_H
#define DriveSub_H
#include <WPILib.h>
#include <Commands/Subsystem.h>
#include <ctre/Phoenix.h>

class DriveSub : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	WPI_TalonSRX* Front_Left_Motor;
	WPI_TalonSRX* Front_Right_Motor;
	WPI_TalonSRX* Middle_Left_Motor;
	WPI_TalonSRX* Middle_Right_Motor;
	WPI_TalonSRX* Back_Left_Motor;
	WPI_TalonSRX* Back_Right_Motor;
	DoubleSolenoid* Gear_Box;
public:
	DriveSub();
	void Drive(double speed, double turn);
	void Shift(DoubleSolenoid::Value value);
	void InitDefaultCommand();
};

#endif  // DriveSub_H

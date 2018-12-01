#include <PID6Output.h>

Motor6PIDOutput::Motor6PIDOutput(
		WPI_TalonSRX* Front_Left_Motor,
		WPI_TalonSRX* Front_Right_Motor,
		WPI_TalonSRX* Middle_Left_Motor,
		WPI_TalonSRX* Middle_Right_Motor,
		WPI_TalonSRX* Back_Left_Motor,
		WPI_TalonSRX* Back_Right_Motor)
{
}

Motor6PIDOutput::~Motor6PIDOutput() {

}

void Motor6PIDOutput::PIDWrite(double value)
{
	Front_Left_Motor->Set(value);
	Front_Right_Motor->Set(value);
	Middle_Left_Motor->Set(value);
	Middle_Right_Motor->Set(value);
	Back_Left_Motor->Set(value);
	Back_Right_Motor->Set(value);
}


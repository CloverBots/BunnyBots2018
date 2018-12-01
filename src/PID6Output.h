#ifndef Motor6PIDOutput_H_
#define Motor6PIDOutput_H_
#include <WPILib.h>
#include <ctre/Phoenix.h>

class Motor6PIDOutput : public PIDOutput{
private:
	WPI_TalonSRX* Front_Left_Motor;
	WPI_TalonSRX* Front_Right_Motor;
	WPI_TalonSRX* Middle_Left_Motor;
	WPI_TalonSRX* Middle_Right_Motor;
	WPI_TalonSRX* Back_Left_Motor;
	WPI_TalonSRX* Back_Right_Motor;
public:
	Motor6PIDOutput(
	WPI_TalonSRX* Front_Left_Motor,
	WPI_TalonSRX* Front_Right_Motor,
	WPI_TalonSRX* Middle_Left_Motor,
	WPI_TalonSRX* Middle_Right_Motor,
	WPI_TalonSRX* Back_Left_Motor,
	WPI_TalonSRX* Back_Right_Motor);
	virtual ~Motor6PIDOutput();
	virtual void PIDWrite(double value);
};

#endif /* Motor6PIDOutput_H_ */

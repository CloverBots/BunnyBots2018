#ifndef BallConveyor_H
#define BallConveyor_H
#include <WPILib.h>
#include <Commands/Subsystem.h>

class BallConveyor : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Talon* Ball_Conveyor_Motor;
public:
	BallConveyor();
	void SetSpeed(double speed);
	void InitDefaultCommand();
};

#endif  // BallConveyor_H

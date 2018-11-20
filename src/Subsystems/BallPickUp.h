#ifndef BallPickUp_H
#define BallPickUp_H
#include "WPILib.h"
#include <Commands/Subsystem.h>

class BallPickUp : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Talon* Ball_Pick_Up_Motor;
public:
	BallPickUp();
	void SetSpeed(double speed);
	void InitDefaultCommand();
};

#endif  // BallPickUp_H
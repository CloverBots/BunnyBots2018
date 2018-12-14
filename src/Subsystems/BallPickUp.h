#pragma once

#include "WPILib.h"
#include <Commands/Subsystem.h>
#include <ctre/Phoenix.h>

class BallPickUp : public Subsystem
{
private:
	WPI_TalonSRX* Ball_Pick_Up_Motor;

public:
	BallPickUp();
	void SetSpeed(double speed);
	void InitDefaultCommand();
};

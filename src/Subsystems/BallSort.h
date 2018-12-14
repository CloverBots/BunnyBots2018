#pragma once

#include <Commands/Subsystem.h>
#include <WPILib.h>

const int COMMAND_REGISTER_BIT = 0x80;
const int MULTI_BYTE_BIT    = 0x20;

const int ENABLE_REGISTER   = 0x00;
const int ATIME_REGISTER    = 0x01;
const int PPULSE_REGISTER   = 0x0E;

const int ID_REGISTER       = 0x12;
const int CDATA_REGISTER    = 0x14;
const int RDATA_REGISTER    = 0x16;
const int GDATA_REGISTER    = 0x18;
const int BDATA_REGISTER    = 0x1A;
const int PDATA_REGISTER    = 0x1C;

class BallSort : public frc::Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Relay* solenoid;
	I2C* color_sensor;

	uint8_t data[6];
	uint8_t red_value;
	uint8_t green_value;
	uint8_t blue_value;

public:
	BallSort();
	void SetSolenoid(Relay::Value value);
	void UpdateSensor();
	bool IsRed();
	bool IsBlue();
	void InitDefaultCommand() override;
};


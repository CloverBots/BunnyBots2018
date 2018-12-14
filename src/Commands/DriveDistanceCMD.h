#pragma once

#include <Commands/Command.h>

class DriveDistanceCMD : public frc::Command
{
private:
	double distance;
public:
	DriveDistanceCMD(double distance);
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};


#pragma once

#include <Commands/Command.h>

class BallSortCMD : public frc::Command
{
public:
	BallSortCMD();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};


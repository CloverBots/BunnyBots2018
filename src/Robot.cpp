#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <TimedRobot.h>
#include "CommandBase.h"
#include "Commands/DriveDistance.h"

class Robot : public frc::TimedRobot {
public:
	DriverStation& ds = DriverStation::GetInstance();
	Compressor *c = new Compressor(0);
	void RobotInit() override {
		m_chooser.AddDefault("DriveForward", "DriveForward");
		frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
	}

	/**
	 * This function is called once each time the robot enters Disabled
	 * mode.
	 * You can use it to reset any subsystem information you want to clear
	 * when
	 * the robot is disabled.
	 */
	void DisabledInit() override {c->Stop();}

	void DisabledPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
	}

	void AutonomousInit() override {
		c->Start();
		CommandBase::oi->SetTeam(ds.GetAlliance());
		std::string autoSelected = frc::SmartDashboard::GetString(
				"Auto Selector", "Default");
		if (autoSelected == "DriveForward") {
			m_autonomousCommand = new DriveDistance(100);
		} else {
			m_autonomousCommand = new DriveDistance(100);
		}

		if (m_autonomousCommand != nullptr) {
			m_autonomousCommand->Start();
		}
	}

	void AutonomousPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
	}

	void TeleopInit() override {
		c->Start();
		CommandBase::oi->SetTeam(ds.GetAlliance());
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (m_autonomousCommand != nullptr) {
			m_autonomousCommand->Cancel();
			m_autonomousCommand = nullptr;
		}
	}

	void TeleopPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
	}

	void TestPeriodic() override {

	}

private:
	// Have it null by default so that if testing teleop it
	// doesn't have undefined behavior and potentially crash.
	frc::Command* m_autonomousCommand = nullptr;
	frc::SendableChooser<std::string> m_chooser;
};

START_ROBOT_CLASS(Robot)

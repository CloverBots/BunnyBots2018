#ifndef DriveSub_H
#define DriveSub_H
#include <WPILib.h>
#include <Commands/Subsystem.h>
#include <ctre/Phoenix.h>
#include <PIDValOutput.h>
#include "../Enc2PIDSource.h"

class DriveSub : public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	float DistanceRight = 0;
	float DistanceLeft = 0;
	float DistanceOldRight = 0;
	float DistanceOldLeft = 0;
	const float m_WheelDiameter = 6;
	const float m_WheelCircumference = m_WheelDiameter * M_PI;
	const float m_EncScaler = 2.8444;
	float m_DriveP = 0.015f;
	float m_DriveI = 0.0f;
	float m_DriveD = 0.1f;
	float m_RotateP = 0.02f;
	float m_RotateI = 0.0f;
	float m_RotateD = 0.01f;


	WPI_TalonSRX* Front_Left_Motor;
	WPI_TalonSRX* Front_Right_Motor;
	WPI_TalonSRX* Middle_Left_Motor;
	WPI_TalonSRX* Middle_Right_Motor;
	WPI_TalonSRX* Back_Left_Motor;
	WPI_TalonSRX* Back_Right_Motor;
	DoubleSolenoid* Gear_Box;
	Enc2PIDSource* DriveSource;
	PIDValOutput* DriveOutput;
	PIDValOutput* RotateOutput;

	ADXRS450_Gyro* m_gyro;
	PIDController* DrivePID;
	PIDController* DriveRotatePID;
public:
	DriveSub();
	void Drive(double speed, double turn);
	void Shift(DoubleSolenoid::Value value);
	double GetDriveOutput();
	double GetRotateOutput();
	void ResetGyro();
	void ResetDrive();
	double GetDistance();
	double GetGyroAngle();
	void PIDDrive();
	void SetDrivePIDEnabled(bool enabled);
	void SetDriveRotatePIDEnabled(bool enabled);
	void SetDriveRotate(bool enabled, double setpoint);
	void SetDrive(bool enabled, double setpoint);
	bool OnTarget();
	void UpdateFromSmartDashboard();
	void DisableAllPID();
	void Calibrate();
	void InitDefaultCommand();
};

#endif  // DriveSub_H

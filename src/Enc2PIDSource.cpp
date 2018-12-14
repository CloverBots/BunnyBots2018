#include "Enc2PIDSource.h"
#include <ctre/Phoenix.h>
#include <iostream>

Enc2PIDSource::Enc2PIDSource(WPI_TalonSRX* pTalonRight, WPI_TalonSRX* pTalonLeft)
			: m_pTalonRight(pTalonRight), m_pTalonLeft(pTalonLeft)
{

}

Enc2PIDSource::~Enc2PIDSource()
{
}

double Enc2PIDSource::PIDGet()
{
//	DistanceRight += (m_pTalonRight->GetSelectedSensorPosition(0) / 54.3702 / 21.6 - DistanceOldRight);
//	DistanceOldRight = DistanceRight;
//	DistanceLeft += (m_pTalonLeft->GetSelectedSensorPosition(0) / 54.3702 / 21.6 - DistanceOldLeft);
//	DistanceOldLeft = DistanceLeft;
	DistanceRight += (m_pTalonRight->GetSelectedSensorPosition(0) / 54.3702 / (21.6) - DistanceOldRight);
	DistanceOldRight = DistanceRight;
	DistanceLeft += (m_pTalonLeft->GetSelectedSensorPosition(0) / 54.3702 / (21.6) - DistanceOldLeft);
	DistanceOldLeft = DistanceLeft;
	return -((DistanceRight + DistanceLeft) / 2);
}

void Enc2PIDSource::Reset()
{
	DistanceLeft = 0;
	DistanceRight = 0;
	DistanceOldLeft = 0;
	DistanceOldRight = 0;
	m_pTalonLeft->GetSensorCollection().SetQuadraturePosition(0, 10);
	m_pTalonRight->GetSensorCollection().SetQuadraturePosition(0, 10);
}

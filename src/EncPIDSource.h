#pragma once

#include "WPILib.h"
#include <ctre/Phoenix.h>

class EncPIDSource : public PIDSource
{
private:

	WPI_VictorSPX* m_pTalon;
public:
	EncPIDSource(WPI_VictorSPX* pTalon);
	void Reset();
	virtual ~EncPIDSource();
	virtual double PIDGet();
};

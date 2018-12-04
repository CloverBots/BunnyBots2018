/*
 * EncPIDSource.h
 *
 *  Created on: Feb 16, 2018
 *      Author: conso
 */

#pragma once

#include "WPILib.h"
#include <ctre/Phoenix.h>

class EncPIDSource : public PIDSource
{
private:

	WPI_TalonSRX* m_pTalon;
public:
	EncPIDSource(WPI_TalonSRX* pTalon);
	void Reset();
	virtual ~EncPIDSource();
	virtual double PIDGet();
};

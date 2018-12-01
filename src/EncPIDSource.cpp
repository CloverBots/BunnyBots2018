/*
 * EncPIDSource.cpp
 *
 *  Created on: Feb 16, 2018
 *      Author: conso
 */

#include "EncPIDSource.h"
#include <ctre/Phoenix.h>
#include <iostream>

EncPIDSource::EncPIDSource(WPI_TalonSRX* pTalon) : m_pTalon(pTalon)
{

}

EncPIDSource::~EncPIDSource()
{
}

double EncPIDSource::PIDGet()
{
	return m_pTalon->GetSelectedSensorPosition(0);
}

void EncPIDSource::Reset()
{
	m_pTalon->GetSensorCollection().SetQuadraturePosition(0, 10);
}

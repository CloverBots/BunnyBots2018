/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "CubeAutoCMDGroup.h"

CubeAutoCMDGroup::CubeAutoCMDGroup()
{
	AddParallel(new CubePickUpAutoCMD(false, -.8, .35));
	AddParallel(new CubeConveyorAutoCMD());
	AddParallel(new BallSortAutoCMD());
	AddParallel(new BallConveyorAutoCMD(.45));
	AddSequential(new DriveDistanceCMD(.27));
}

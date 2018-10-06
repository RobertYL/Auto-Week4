/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "MiddleRight.h"

MiddleRight::MiddleRight() {
  AddSequential(new Turn(90));
	AddSequential(new DriveForward(GRE/2));
	AddSequential(new Turn(-90));
	AddSequential(new DriveForward(ORA));
}

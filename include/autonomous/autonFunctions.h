#pragma once // I don't remember why this is here, but it looks important
#include "vex.h"
#include "autonomous/drivePID.h"

double inToRev();

// What unique about when we make runTask a global variable is that it takes inputs
// As such we include those inputs here and also give some of them pre-existing
// values so that we can simplify our final code
// i.e. because we specify maxSpeed as 6 here, when we call runTask(20), the maxSpeed is set to 6 automatically.
// If we call runTask(20, 270, 12), assuming the current angle is 270, the maxSpeed is set to 12 for ONLY this call of runTask
void runTask(double driveDist, double turnDist = desiredTurnValue, double maxSpeed = 6);
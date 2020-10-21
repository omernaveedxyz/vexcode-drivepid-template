/*----------------------------------------------------------------------------*/
/*                                                                            */
/*       This is where you declare the variables you want to instantiate      */
/*       as global variables. Global variables are variables that can be      */
/*       called outside of the file. i.e. declaring a motor_group here will   */
/*                 allow you to call it from any file.                        */
/*                                                                            */
/*----------------------------------------------------------------------------*/
//

// These include statements give you contain pre-configured functions such as setPosition etc.
// Only reason to change this is to add support for new Vex part (i.e. vex imu)
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include "v5.h"
#include "v5_vcs.h"
#include "robot-config.h"

// I recommend declaring all of your variables as extern variables just to make life easier
// ---- START vex.h EXTERN VARIABLES ----
extern competition Competition;

extern controller master;

extern motor rightDtFront;
extern motor rightDtBack;
extern motor leftDtFront;
extern motor leftDtBack;

extern inertial iSensor;

extern motor_group rightDt;
extern motor_group leftDt;

extern task drivePIDTask;
// ---- END vex.h EXTERN VARIABLES ----

#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)
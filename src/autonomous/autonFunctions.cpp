#include "vex.h"
#include "autonomous/drivePID.h"

// Converts inches to revolutions for DrivePID
double inToRev(double inches) {
  // Equation: distance / (pi * diameter of wheels)
  // or 
  // Equation: distance / (circumference of wheels)
  return (inches / (M_PI * 4) );
}

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*  This is essentialy the main function related to DrivePID. Once you get    */
/*  your PID tuned, you will almost never need to touch it. Instead, you call */
/*  this function. What this function does is change all relavent variables   */
/*  related to DrivePID based on what you specify so that the PID moves       */ 
/*  accordingly. How this works is that since DrivePID is constantly running  */ 
/*  in the background because it is a task, it constantly checks the values of*/ 
/*  these variables. Once any of them changes, the PID is alerted and goes    */
/*  into motion. This runTask is what changes those variables to alert the PID*/ 
/*  to get moving.                                                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/
//
void runTask(double driveDist, double turnDist, double maxSpeed) {
  if(driveDist != 0) {
    maxSpeedDrive = maxSpeed;
    resetDriveSensors = true;
    desiredTarget = inToRev(driveDist);
  }
  desiredTurnValue = turnDist;
  count = 0;
  isRunning = true;
}
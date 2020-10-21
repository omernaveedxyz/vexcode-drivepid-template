/*----------------------------------------------------------------------------*/
/*                                                                            */
/*       This is where you would make an auton selector as well as            */
/*         initialize any code to run before the round begins                 */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

void pre_auton() {
  vexcodeInit();

  // Calibrate IMU
  iSensor.calibrate(2000);
  this_thread::sleep_for(2000);
  std::cout << "done calibrating imu" << std::endl;

  // Reset motor rotations
  rightDtFront.resetRotation();
  rightDtBack.resetRotation();
  leftDtFront.resetRotation();
  leftDtBack.resetRotation();

  // Set motor brake types
  rightDtFront.setBrake(coast);
  rightDtBack.setBrake(coast);
  leftDtFront.setBrake(coast);
  leftDtBack.setBrake(coast);
}
#include "vex.h"
#include "autonomous/autonFunctions.h"

void onePointAuton() {
  iSensor.setRotation(270, rotationUnits::deg); // Set starting angle for robot
  runTask(0, 270); // Set starting angle for task (same as above)
  drivePIDTask = vex::task(drivePID); // Start DrivePID task
  enableDrivePID = true; // Also required to start DrivePID
  
  // Unfortunately I was not able to figure out how to call runTask without also running
  // a while loop directly below it. If the while loop is not put, the code skips to the
  // final runTask and only executes that.
  // TLDR; have a while loop below each runTask


  // Examples
  // runTask(20) -> Forward 20 inches
  // runTask(-20) -> Backward 20 inches
  // runTask(0, 180) -> Rotate to 180 deg
  // runTask(10, 180) -> Drive 10 inches forward while also rotating to 180 deg
  // runTask(20, 180, 12) -> Drive 10 inches forward while also rotating to 180 deg at maxSpeed of 12v
  // runTask always requires at least the distance, but the angle and maxSpeed are optional

  // runTask(24); // Move forward 20 inches
  // while(isRunning) {
  //   wait(10, msec);
  // }

  runTask(0, 180); // This will change the angle the robot is facing
  while(isRunning) {
    wait(10, msec);
  }

  // runTask(10, 270); // You can even do both at the same time for cool arc turns
  // while(isRunning) {
  //   wait(10, msec);
  // }
}
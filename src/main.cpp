// This grabs all of the global variables stored in these files for us to use
#include "vex.h" 
#include "pre_auton.h"
#include "autonomous/auton.h"
#include "driverControl/driver.h"

// ---- START CONFIGURED DEVICES ----
competition Competition;

vex::controller master(vex::controllerType::primary);

// vex::motor NAME(vex::PORT,vex::gearSetting::RATIO, REVERSED?)
vex::motor rightDtFront(vex::PORT10, vex::gearSetting::ratio18_1, true);
vex::motor rightDtBack(vex::PORT11, vex::gearSetting::ratio18_1, true);
vex::motor leftDtFront(vex::PORT20, vex::gearSetting::ratio18_1, false);
vex::motor leftDtBack(vex::PORT12, vex::gearSetting::ratio18_1, false);

vex::inertial iSensor(vex::PORT19);

// motor_group NAME(MOTOR1, MOTOR2, MOTOR3, etc)
motor_group rightDt(rightDtFront, rightDtBack);
motor_group leftDt(leftDtFront, leftDtBack);
// ---- END CONFIGURED DEVICES ----

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*  Tasks are what allow the robot to perform multiple commands at the same   */ 
/*  time. While the robot continues the code in main(), it also performs the  */
/*  code in each task at the same time. This allows for deeper control of the */
/*  robot, but we mostly use it to simplify the amount of repetitive code we  */
/*  need to write. This will make sense later.                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
//
// ---- START TASKS ----
task drivePIDTask;
// ---- END TASKS ----

int main() {
  pre_auton();

  Competition.autonomous(auton);
  Competition.drivercontrol(driver);

  while(true) {
    wait(10, msec);
  }
}

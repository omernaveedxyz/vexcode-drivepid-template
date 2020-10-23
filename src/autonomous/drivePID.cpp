/*----------------------------------------------------------------------------*/
/*                                                                            */
/*  Although this is maybe the most confusing file, I would not be able to    */
/*  explain PID through text alone. I would suggest watching videos and doing */
/*  your own research to learn about exactly how PID works.                   */
/*                                                                            */
/*----------------------------------------------------------------------------*/
//
#include "vex.h"

bool enableDrivePID = false;
bool resetDriveSensors = false;
bool isRunning = true;

// ---- START TUNING VARIABLES ----
double kP = 100;
double kD = 0;

double turnkP = 0.13;
double turnkD = 0.1;
// ---- END TUNING VARIABLES ----

int count = 0;
int countDeriv = 0;

double error;
double prevError = 0;
double derivative;

double turnError;
double turnPrevError = 0;
double turnDerivative;

double desiredTarget = 0;
double desiredTurnValue = 270;
double maxSpeedDrive = 6;
double maxSpeedTurn = 9;

int drivePID() {
  while(1) {
    while(enableDrivePID) {
      if(resetDriveSensors) {
        rightDt.resetRotation();
        leftDt.resetRotation();
        resetDriveSensors = false;
      }

      double leftMotorRotation = leftDtBack.rotation(rev);
      double rightMotorRotation = rightDtBack.rotation(rev);
      double averageRotation = (leftMotorRotation + rightMotorRotation) / 2;

      error = desiredTarget - averageRotation;
      derivative = error - prevError;

      double lateralMotorPower = (kP*error) + (kD*derivative);
      ///////////////////////
      ///////////////////////
      turnError = desiredTurnValue - iSensor.rotation(deg);
      turnDerivative = turnError - turnPrevError;

      double turnMotorPower = (turnkP*turnError) + (turnkD*turnDerivative);
       ///////////////////////
      ///////////////////////
      // std::cout << "averageRotation: " << averageRotation << std::endl;
      // std::cout << "error: " << error << std::endl;
      // std::cout << "derivative: " << derivative << std::endl;
      // std::cout << "motorPower: " << lateralMotorPower << std::endl;
      // std::cout << "iSensor: " << iSensor.rotation(deg) << std::endl;
      // std::cout << "turnError: " << turnError << std::endl;
      // std::cout << "turnDerivative: " << turnDerivative << std::endl;
      // std::cout << "turnPower: " << turnMotorPower << std::endl;
      // std::cout << "resetDriveSensors: " << resetDriveSensors << std::endl;
      // std::cout << "isRunning: " << isRunning << std::endl;
      // std::cout << "////" << std::endl;
      ///////////////////////
      ///////////////////////
      if(lateralMotorPower > maxSpeedDrive) {
        lateralMotorPower = maxSpeedDrive;
      } else if(lateralMotorPower < -maxSpeedDrive) {
        lateralMotorPower = -maxSpeedDrive;
      }

      if(turnMotorPower > maxSpeedTurn) {
        turnMotorPower = maxSpeedTurn;
      } else if (turnMotorPower < -maxSpeedTurn) {
        turnMotorPower = -maxSpeedTurn;
      }

      leftDt.spin(fwd, lateralMotorPower + turnMotorPower, volt);
      rightDt.spin(fwd, lateralMotorPower - turnMotorPower, volt);

      if(fabs(error) < 0.01 && fabs(turnDerivative) < 0.1) {
        count++;
      } 
      else {
        count = 0;
      }

      if(fabs(derivative) < 0.005) {
        countDeriv++;
      }
      else {
        countDeriv = 0;
      }

      if(count >= 5 || countDeriv >= 35) {
        isRunning = false;
      }

      prevError = error;
      turnPrevError = turnError;
      this_thread::sleep_for(15);
    }
    this_thread::sleep_for(15);
  }
  return 1;
}
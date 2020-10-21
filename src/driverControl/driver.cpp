#include "vex.h"

void driver() {
  // It is vital for you to stop any tasks from auton before driver control begins
  // Otherwise they will continue and conflict with input from the driver
  drivePIDTask.stop();

  // You can also initialize tasks for the driver here in order to decrease the
  // length of this file.

  while(1) {
    //RightDt
    if( abs(master.Axis2.value()) > 0.1 ) {
      // This currently contains a cube-root curve to allow for a more natural increase
      // in motor voltage, but can be removed if not wanted
      // i.e. 
      // rightDt.spin(vex::directionType::fwd, ( master.Axis2.value() * 0.01 * 12, voltageUnits::volt);
      //
      // The reason the value is multiplied by 0.01 is to convert it into a percent
      // Since the maximum voltage is 12v but the maximum value is 100, we need to
      // do this in order to correctly control the motor
      rightDt.spin(vex::directionType::fwd, ( pow( master.Axis2.value(),3) / 10000 ) * 0.01 * 12, voltageUnits::volt);
    }
    else {
      rightDt.stop(coast);
    }

    //LeftDt
    if( abs(master.Axis3.value()) > 0.1 ) {
      leftDt.spin(vex::directionType::fwd, ( pow( master.Axis3.value(),3) / 10000 ) * 0.01 * 12, voltageUnits::volt); 
    }
    else {
      leftDt.stop(coast);
    }

    /* 
    // Buttons Example
    if(master.ButtonA.pressing()){
      dt.spin(vex::directionType::fwd, driveSpeedFront, voltageUnits::volt);
    } 
    */

    this_thread::sleep_for(15);    
  }
}
#include "vex.h"
#include "autonomous/onePointAuton.h"

int autonomousMode = 0; //This will decide what auton mode to run

void auton() {
  // switch(autonomousMode) {
  //   case 0 :
  //     onePointAuton();
  //   // case 1 :
  //     // otherAuton();
  //   default :
  //     std::cout << "Invalid value for autonomousMode" << std::endl;
  // }
  onePointAuton();
}
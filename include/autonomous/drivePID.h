#include "vex.h"

extern bool enableDrivePID;
extern bool resetDriveSensors;
extern bool isRunning;

extern double desiredTarget;
extern double desiredTurnValue;
extern double maxSpeedDrive;
extern int count;

int drivePID(); // This returns an int because all tasks are required to return ints for some reason
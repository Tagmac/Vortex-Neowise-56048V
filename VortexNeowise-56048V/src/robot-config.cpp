#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
/*vex-vision-config:begin*/
signature VisionSensor__YESIL = signature (1, 0, 0, 0, 0, 0, 0, 3, 0);
signature VisionSensor__MAVI = signature (2, -3501, -2397, -2949, 7915, 10121, 9018, 5.1, 0);
signature VisionSensor__SIG_3 = signature (3, 0, 0, 0, 0, 0, 0, 3, 0);
signature VisionSensor__SIG_4 = signature (4, 0, 0, 0, 0, 0, 0, 3, 0);
signature VisionSensor__SIG_5 = signature (5, 0, 0, 0, 0, 0, 0, 3, 0);
signature VisionSensor__SIG_6 = signature (6, 0, 0, 0, 0, 0, 0, 3, 0);
signature VisionSensor__SIG_7 = signature (7, 0, 0, 0, 0, 0, 0, 3, 0);
vision VisionSensor = vision (PORT7, 50, VisionSensor__YESIL, VisionSensor__MAVI, VisionSensor__SIG_3, VisionSensor__SIG_4, VisionSensor__SIG_5, VisionSensor__SIG_6, VisionSensor__SIG_7);
/*vex-vision-config:end*/

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}
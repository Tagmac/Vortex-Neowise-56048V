#include "vex.h"
using namespace vex;

competition Competition;
vex::motor solmotor = vex::motor (vex::PORT1);
vex::motor sagmotor = vex::motor (vex::PORT10,true);
vex::motor shooter = vex::motor (vex::PORT12,true);
vex::motor ortamotor = vex::motor (vex::PORT20);
vex::motor grabbersag = vex::motor (vex::PORT2,true);
vex::motor arkamotor = vex::motor (vex::PORT8);
vex::motor grabbersol = vex::motor (vex::PORT6, true);
vex::motor arkaustmotor = vex::motor (vex::PORT11);
vex::controller kumanda = vex::controller();
void pre_auton(void) {

  vexcodeInit();
}
void autonomous(void) {
  //VISIONSENSOR CODES
  int centerFOV = 158;
  int offsetX = 15; 
 Brain.Screen.clearLine();
    VisionSensor.takeSnapshot(VisionSensor__YESIL);//"YESIL" is a signature
    if(kumanda.ButtonX.pressing()){  
      if(VisionSensor.largestObject.exists){
        if(VisionSensor.largestObject.centerX > centerFOV + offsetX){
            sagmotor.spin(vex::directionType::rev, 20 , vex::velocityUnits::pct);
            solmotor.spin(vex::directionType::fwd, 20 , vex::velocityUnits::pct);
        }else if(VisionSensor.largestObject.centerX < centerFOV - offsetX){
            sagmotor.spin(vex::directionType::fwd, 20 ,vex::velocityUnits::pct);
            solmotor.spin(vex::directionType::rev, 20 ,vex::velocityUnits::pct);  
        }
        else{
            sagmotor.stop(vex::brakeType::brake);
            solmotor.stop(vex::brakeType::brake);
          } 

}
void usercontrol(void) ;
  int ortamotorhız = 100;
  int shooterhız = 100; 
  int arkamotorhız = 100;
  int yanmotorhız = 100;
  int arkaustmotorhız = 100;
  int grabbersaghız = 100;
  int grabbersolhız = 100;
  int centerFOV = 158;
  int offsetX = 15; 
  while (1) { //while döngüsünü anlat
    solmotor.spin(directionType::fwd, (kumanda.Axis3.value() + kumanda.Axis1.value())/2, velocityUnits::pct); //(Axis3+Axis4)/2;
	  sagmotor.spin(directionType::fwd, (kumanda.Axis3.value() - kumanda.Axis1.value())/2, velocityUnits::pct);//(Axis3-Axis4)/2;
    //GRABBERSAG VE GRABBERSOL KODLARI
    if(kumanda.ButtonR1.pressing()) {
      grabbersag.spin(vex::directionType::fwd,grabbersaghız,vex::velocityUnits::pct);
      grabbersol.spin(vex::directionType::fwd,grabbersolhız,vex::velocityUnits::pct);
    }
    else if(kumanda.ButtonR2.pressing()) {
      grabbersag.spin(vex::directionType::rev,grabbersaghız,vex::velocityUnits::pct);
      grabbersol.spin(vex::directionType::rev,grabbersolhız,vex::velocityUnits::pct);
    }
    else{
      grabbersag.stop (vex::brakeType::brake);
      grabbersol.stop (vex::brakeType::brake);
    }  
    //ORTA SİSTEM KODLARI
    if(kumanda.ButtonL1.pressing()){
      ortamotor.spin(vex::directionType::fwd,ortamotorhız,vex::velocityUnits::pct);
      arkamotor.spin(vex::directionType::fwd,arkamotorhız,vex::velocityUnits::pct);
      arkaustmotor.spin(vex::directionType::fwd,arkaustmotorhız,vex::velocityUnits::pct);
      shooter.spin(vex::directionType::fwd,arkaustmotorhız,vex::velocityUnits::pct);
    }
    else if(kumanda.ButtonL2.pressing()) {
      arkamotor.spin(vex::directionType::fwd,arkamotorhız,vex::velocityUnits::pct);
      arkaustmotor.spin(vex::directionType::rev,arkaustmotorhız,vex::velocityUnits::pct);
    }
    else{
      arkamotor.stop(vex::brakeType::hold);
      arkaustmotor.stop(vex::brakeType::hold);
      ortamotor.stop(vex::brakeType::hold);
      shooter.stop(vex::brakeType::hold);
    }
   
    
    wait(20, msec); 
  }
}
}
int main() {

  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();

  while (true) {
    wait(100, msec);
  }
}
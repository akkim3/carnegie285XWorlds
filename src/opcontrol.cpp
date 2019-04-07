#include "main.h"
#include "flywheelutil\flywheel.hpp"
#include "C:\Users\clove\Desktop\X4\src\robotUtil\initRobot.hpp"
/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
 //Front Right Motor: -2
 //Front Left Motor: 1
 //Back Right Motor: -10
 //Back Left Motor: 9
 //Intake: 8
 //Indexer: 3
 //Flywheel: 6
 //Scraper
 Controller controller;
 ControllerButton flywheelShoot (ControllerDigital::R1);
 ControllerButton placeholder (ControllerDigital::R2);
 ControllerButton intakeFwd (ControllerDigital::L1);
 ControllerButton intakeRev (ControllerDigital::L2);

 ControllerButton doubleShotTest (ControllerDigital::A);
bool intakeOn = false;
bool intakeRevOn = false;
 void toggleIntake(){
   intakeOn = !intakeOn;
   if(intakeOn){
     intakeRevOn = false;
     intake.moveVoltage(10000);
   } else{
     intake.moveVoltage(0);
   }
 }
 void toggleIntakeRev(){
   intakeRevOn = !intakeRevOn;
   if(intakeRevOn){
     intakeOn = false;
   intake.moveVoltage(-10000);
   indexer.moveVoltage(-10000);
} else{
intake.moveVoltage(0);
indexer.moveVoltage(0);

}
 }
void doubleShot(){
  indexer.moveVelocity(600);
  pros::delay(200);
  scraper.moveRelative(-120, 200);
  pros::delay(200);
  scraper.moveRelative(-120, 200);
}

void opcontrol() {
  intake.setGearing(AbstractMotor::gearset::blue);
  //flywheel.setGearing(AbstractMotor::gearset::blue);
  indexer.setGearing(AbstractMotor::gearset::green);

  scraper.moveAbsolute(95, 100);
  scraper.tarePosition();
	while(true){
    //intake.moveVelocity();
    flywheelControl();
    //flywheelA.setMaxVelocity(536);
    //flywheelA.moveVelocity(535);
    if(intakeFwd.changedToPressed()){
      toggleIntake();

    }
    if(intakeRev.changedToPressed()){
      toggleIntakeRev();

    }
    if(placeholder.isPressed()){

      scraper.moveAbsolute(325,200);

    }
    if(placeholder.changedToReleased()){

      scraper.moveAbsolute(0, 200);
    }
    if(flywheelShoot.isPressed()){
      indexer.moveVelocity(200);
      intake.moveRelative(360, 200);
    }else{

      indexer.moveVelocity(0);

    }
    if(doubleShotTest.changedToPressed()){

        doubleShot();
    }
    drive.arcade(controller.getAnalog(ControllerAnalog::leftY),controller.getAnalog(ControllerAnalog::rightX));
    //drive.arcade(controller.getAnalog(ControllerAnalog::leftY), controller.getAnalog(ControllerAnalog::rightX));
		pros::delay(20);
	}
}

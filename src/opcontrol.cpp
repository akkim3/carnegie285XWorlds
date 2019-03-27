#include "C:\Users\clove\Desktop\X4\include\main.h"
#include "C:\Users\clove\Desktop\X4\src\flywheelutil\flywheel.hpp"
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

 okapi::Motor intake {8};
 okapi::Motor flywheelA {7};
okapi::Motor indexer {3};
 auto drive = ChassisControllerFactory::create(
   {1,9},
   {-10,-2},
   AbstractMotor::gearset::green,
   {4.125_in, 12.125_in}
 );
void opcontrol() {
  intake.setGearing(AbstractMotor::gearset::blue);
  flywheelA.setGearing(AbstractMotor::gearset::blue);
  indexer.setGearing(AbstractMotor::gearset::green);
	while(true){
    //intake.moveVelocity();
    flywheelControl();
    //flywheelA.setMaxVelocity(536);
    //flywheelA.moveVelocity(535);
    if(intakeFwd.isPressed() && !intakeRev.isPressed() && !placeholder.isPressed()){
      intake.moveVelocity(200);
      }
    else if(intakeRev.isPressed() && !intakeFwd.isPressed() && !placeholder.isPressed()){
        intake.moveVelocity(-200);
        }
    else if(intakeRev.isPressed() && intakeFwd.isPressed() && !placeholder.isPressed()){
          intake.moveVelocity(-120);
          indexer.moveVelocity(-120);
          }
  else if(!intakeRev.isPressed() && !intakeFwd.isPressed() && placeholder.isPressed()){

          }
  else if(intakeRev.isPressed() && !intakeFwd.isPressed() && placeholder.isPressed()){

          }
    else{
        intake.moveVelocity(0);
        indexer.moveVelocity(0);
      }
    if(flywheelShoot.isPressed()){
      indexer.moveVelocity(200);
      intake.moveVelocity(400);
    }
    drive.arcade(controller.getAnalog(ControllerAnalog::leftY), controller.getAnalog(ControllerAnalog::rightX));
		pros::delay(20);
	}
}

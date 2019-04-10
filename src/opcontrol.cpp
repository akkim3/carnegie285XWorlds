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
 ControllerButton changeRPMUp (ControllerDigital::X);
 ControllerButton changeRPMDown (ControllerDigital::Y);
//bool //intakeOn = false;
//bool //intakeRevOn = false;

void doubleShot(){
  indexer.moveVelocity(600);
  intake.moveVelocity(200);
  pros::delay(600);
  scraper.moveAbsolute(-95, 200);
  pros::delay(1000);
  scraper.moveAbsolute(0, 200);
}
double tRPM = 470*5;
void opcontrol() {
  intake.setGearing(AbstractMotor::gearset::green);
  flywheel-> setGearing(AbstractMotor::gearset::blue);
  indexer.setGearing(AbstractMotor::gearset::blue);

  scraper.moveAbsolute(95, 100);
  scraper.tarePosition();
	while(true){
    //intake.moveVelocity();
    flywheelControl(tRPM);
    //flywheelA.setMaxVelocity(536);
    //flywheelA.moveVelocity(535);
    if(intakeFwd.isPressed() && !intakeRev.isPressed() && !placeholder.isPressed() && !flywheelShoot.isPressed()){

     intake.moveVelocity(200);

     }

   else if(intakeRev.isPressed() && !intakeFwd.isPressed() && !placeholder.isPressed() && !flywheelShoot.isPressed()){

       intake.moveVelocity(-200);

       }

   else if(intakeRev.isPressed() && intakeFwd.isPressed() && !placeholder.isPressed() && !flywheelShoot.isPressed()){

         intake.moveVelocity(-120);

         indexer.moveVelocity(-120);

         }

 else if(!intakeRev.isPressed() && !intakeFwd.isPressed() && placeholder.isPressed() && !flywheelShoot.isPressed()){



         }

 else if(intakeRev.isPressed() && !intakeFwd.isPressed() && placeholder.isPressed() && !flywheelShoot.isPressed() ){



         }
         else if(!intakeRev.isPressed() && !intakeFwd.isPressed() && !placeholder.isPressed() && flywheelShoot.isPressed() ){

           indexer.moveVelocity(600);
           intake.moveVelocity(200);

                 }


   else{

       intake.moveVelocity(0);

       indexer.moveVelocity(0);

     }


  /*  if(flywheelShoot.isPressed()){

    }else{
      indexer.moveVelocity(0);
      intake.moveVelocity(0);
    }
*/
    if(doubleShotTest.changedToPressed()){

        doubleShot();
    }
  /*  if(changeRPMUp.changedToPressed()){
      flywheelControl(460*5);
    }
    if(changeRPMDown.changedToPressed()){
      flywheelControl(420*5);
    }
    */
    drive.arcade(controller.getAnalog(ControllerAnalog::leftY),controller.getAnalog(ControllerAnalog::rightX));
    //drive.arcade(controller.getAnalog(ControllerAnalog::leftY), controller.getAnalog(ControllerAnalog::rightX));
		pros::delay(20);
	}
}

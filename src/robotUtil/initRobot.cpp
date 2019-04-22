#include "C:\Users\clove\Desktop\X4\src\robotUtil\initrobot.hpp"
#include "main.h"

Motor scraper (4, true, AbstractMotor::gearset::green);;
Motor intake (8, false, AbstractMotor::gearset::green);
Motor* flywheel = new okapi::Motor(7);
Motor indexer (3,false, AbstractMotor::gearset::blue);
pros::ADILineSensor flywheelSensor(2);
pros::ADIPotentiometer scraperPot(3);
float potError = 0;
float potTarget = 3100;
ControllerButton doubleShotTest (ControllerDigital::A);
//auto controller = AsyncControllerFactory::posPID(1, ADIEncoder('A', 'B'), 0.001, 0.0, 0.0001);
void doubleShotTask(void* enable){
/*

  */
  /*
  while(true){
if(doubleShotTest.changedToPressed()){
  indexer.moveVelocity(600);
  intake.moveVelocity(200);
  //scraper.moveAbsolute(0,200);
  //pros::lcd::set_text(3, "%i",flywheelSensor.get_value());
  //cout << flywheelSensor.get_value();
pros::delay(120);
scraper.moveAbsolute(-120, 200);
pros::delay(2000);
scraper.moveAbsolute(0, 200);

//pros::delay(20);
}
}
*/
}
void doubleShot(){
/*

  */
  //while(true){
  indexer.moveVelocity(600);
  intake.moveVelocity(200);
  //scraper.moveAbsolute(0,200);
  //pros::lcd::set_text(3, "%i",flywheelSensor.get_value());
  //cout << flywheelSensor.get_value();
pros::delay(120);
scraper.moveAbsolute(-120, 200);
pros::delay(900);
scraper.moveAbsolute(0, 200);

//pros::delay(20);
}
void slowDoubleShot(){

  indexer.moveVelocity(600);
  intake.moveVelocity(200);
  pros::delay(150);
  indexer.moveVelocity(0);
  intake.moveVelocity(0);
  scraper.moveAbsolute(-120,200);
  pros::delay(500);
  indexer.moveVelocity(600);
  intake.moveVelocity(200);
  pros::delay(500);
  indexer.moveVelocity(0);
  intake.moveVelocity(0);
  scraper.moveAbsolute(0,200);
}

void scrape(){
intake.moveVelocity(200);
scraper.moveAbsolute(280,200);
drive.setMaxVelocity(75);
pros::delay(200);
drive.moveDistanceAsync(-1_ft);
intake.moveVelocity(200);
pros::delay(200);
scraper.moveAbsolute(360,200);
pros::delay(500);
scraper.moveAbsolute(0,200);
intake.moveVelocity(200);
drive.setMaxVelocity(150);
drive.moveDistance(1_ft);


}
void flipCap(){
scraper.moveAbsolute(360,200);
  //drive.moveDistanceAsync(-1_ft);
  drive.setMaxVelocity(100);
  drive.moveDistanceAsync(2_ft);
    pros::delay(700);
    scraper.moveAbsolute(0,200);
    drive.setMaxVelocity(200);

}
void adjustScraper(void* enable){
potError = potTarget - scraperPot.get_value();
while(enable){
if(abs(potError) > 20){
  scraper.moveRelative((-potError),100);

} else{
  //intake.moveVelocity(100);
  scraper.tarePosition();
}
pros::delay(50);
}
}
//}
 ChassisControllerIntegrated drive = ChassisControllerFactory::create(
   {1,9},
   {-10,-2},
   AbstractMotor::gearset::green,
   {4.125_in, 11.75_in}
 );
 AsyncMotionProfileController profileController = AsyncControllerFactory::motionProfile(
   2,  // Maximum linear velocity of the Chassis in m/s
   3,  // Maximum linear acceleration of the Chassis in m/s/s
   15, // Maximum linear jerk of the Chassis in m/s/s/s
  drive // Chassis Controller
 );

#include "main.h"
#include "flywheelutil\flywheel.hpp"
#include "C:\Users\clove\Desktop\X4\src\robotUtil\initRobot.hpp"

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
#include "C:\Users\clove\Desktop\X4\src\robotUtil\initRobot.hpp"
bool on = true;
float bruhMomentum = 900.69;
QLength sideCapDistance = 3.5_ft;
QLength frontFlagDistance = 4.5_ft;
QLength frontCapDistance = 4.0_ft;
QLength midFlagDistance = 1.0_ft;
QLength platformAlignDistance = -4.0_ft;
QLength alliancePlatformDistance = 4.0_ft;
QLength centerPlatformDistance = 6.0_ft;
//pros::ADILineSens flywheelSensor(2);
bool red = true;

void front(){
  scraper.moveAbsolute(0, 200);
  intake.moveVoltage(12000);
  profileController.setTarget("Ball");
  intake.moveVoltage(12000);
  profileController.waitUntilSettled();
  intake.moveVoltage(12000);
  pros::delay(500);
profileController.setTarget("Ball", true); //Go back to starting tile
  intake.moveVelocity(100);
  if(red){
  profileController.generatePath({
  Point{0_ft, 0_ft, 0_deg},
  Point{4_ft, 0_ft, 0_deg}},
  "botFlag"
);}
else{
  profileController.generatePath({
  Point{0_ft, 0_ft, 0_deg},
  Point{4_ft, 0_ft, 0_deg}},
  "botFlag"
);
}
 profileController.waitUntilSettled();
  profileController.removePath("Ball"); //Ball path removed here
  //profileController.removePath("Ball2"); //Ball path removed here

drive.setMaxVelocity(80);
//drive.moveDistance(-0.5_ft);
if(red){
  drive.turnAngle(-85_deg);
  drive.waitUntilSettled();
}else{
  drive.turnAngle(85_deg);
  drive.waitUntilSettled();
}
  intake.moveVelocity(0);
drive.setMaxVelocity(200);

  //Should shoot mid flags here
  //drive.moveDistance(0.5_ft);
  doubleShot();
  intake.moveVelocity(0);
  indexer.moveVelocity(0);
  drive.setMaxVelocity(200);
  //drive.moveDistance(4_ft);

  //drive.setMaxVelocity(150);
  if(red){
    drive.turnAngle(-5_deg);
    drive.waitUntilSettled();
  }else{
    drive.turnAngle(5_deg);
    drive.waitUntilSettled();
  }
  profileController.setTarget("botFlag");
  //drive.moveDistanceAsync(3.5_ft);
  //pros::delay(1500);
  //scraper.moveAbsolute(360, 200);
  //pros::delay(500);
  //scraper.moveAbsolute(0, 200);
  profileController.waitUntilSettled();
  //drive.waitUntilSettled();
  /*
  scraper.moveAbsolute(360, 200);
  pros::delay(500);
  scraper.moveAbsolute(0, 200);
*/
  profileController.setTarget("botFlag", true);
  profileController.waitUntilSettled();


  profileController.removePath("botFlag");
  //drive.setMaxVelocity(10);
  //drive.moveDistance(-4_ft);
  drive.waitUntilSettled();

  drive.setMaxVelocity(80);
  if(red){
    drive.turnAngle(40_deg);
    drive.waitUntilSettled();
  }else{
    drive.turnAngle(-40_deg);
    drive.waitUntilSettled();
  }
  drive.setMaxVelocity(100);
  //drive.moveDistance(1.5_ft);

  drive.moveDistance(2.5_ft);
  //indexer.moveVelocity(200);

  //pros::delay(1000);
  scraper.moveAbsolute(360, 200);
  //drive.waitUntilSettled();
  pros::delay(300);

  drive.moveDistanceAsync(-2_ft);
  intake.moveVelocity(200);
  pros::delay(500);
  scraper.moveAbsolute(0, 200);
  drive.waitUntilSettled();


  //flipCap();

  //scrape();
  //doubleShot();
//  flipCap();



  //Should shoot top and mid flags
  //doubleShot();
  /*profileController.generatePath({
  Point{0_ft, 0_ft, 0_deg},
  Point{2_ft, 0_ft, 0_deg}},
  "Scrape"
  );
  profileController.setTarget("Scrape");
  profileController.waitUntilSettled();
  scrape();
  flipCap();

  profileController.setTarget("Scrape", true);
  intake.moveVelocity(200);
  profileController.waitUntilSettled();
  intake.moveVelocity(0);
  profileController.removePath("Scrape");

  if(red){
    drive.turnAngle(-45_deg);
  }else{
    drive.turnAngle(45_deg);
  }
  //Should shoot top and mid flags
  doubleShot();
  profileController.generatePath({
  Point{0_ft, 0_ft, 0_deg},
  Point{4_ft, 0_ft, 0_deg}},
  "botFlag"
  );
  profileController.setTarget("botFlag");
  profileController.waitUntilSettled();
  profileController.setTarget("botFlag", true);
  profileController.waitUntilSettled();
  profileController.removePath("botFlag");
*/
}
void backSimple(){
  intake.moveVoltage(12000);
  scraper.moveAbsolute(0, 200);
  profileController.generatePath({
   Point{0_ft, 0_ft, 0_deg},  //   (0, 0, 0)
   Point{4_ft, 0_ft, 0_deg}}, //
   "Ball" // Profile name
 );
  profileController.setTarget("Ball");
  intake.moveVelocity(200);
  profileController.waitUntilSettled();
  //pros::delay(500);
  //drive.setMaxVelocity(80);
  //drive.turnAngle(-45_deg);

  //drive.waitUntilSettled();
  //drive.setMaxVelocity(200);
  //doubleShot();
  /*profileController.setTarget("Ball", true);
  profileController.waitUntilSettled();
*/
  drive.setMaxVelocity(100);
  if(red){
    drive.turnAngle(-60_deg);
  }else{
    drive.turnAngle(60_deg);
  }
  //doubleShot();
/*
  drive.setMaxVelocity(200);
  profileController.generatePath({
   Point{0_ft, 0_ft, 0_deg},  //   (0, 0, 0)
   Point{1.5_ft, 0_ft, 0_deg}}, //
   "LineUp" // Profile name
 );
 */
  //profileController.setTarget("LineUp");
  //profileController.waitUntilSettled();
  /*drive.setMaxVelocity(100);
  if(red){
    drive.turnAngle(90_deg);
  }else{
    drive.turnAngle(90_deg);//90
  }
  */
//  drive.setMaxVelocity(100);
///  drive.moveDistance(4_ft);
  //drive.waitUntilSettled();


  /*drive.setMaxVelocity(80);
  drive.moveDistance(0.5_ft);
  drive.waitUntilSettled();
  drive.moveDistance(-0.5_ft);
  drive.waitUntilSettled();
  if(red){
    drive.turnAngle(45_deg);
  }else{
    drive.turnAngle(-45_deg);
  }
  doubleShot();
  */  //intake.moveVelocity(0)
  indexer.moveVelocity(600);

  //doubleShot();

}


void skills(){
  scraper.moveAbsolute(250, 200);
  intake.moveVoltage(12000);
  profileController.setTarget("Ball");
  intake.moveVoltage(12000);
  profileController.waitUntilSettled();
  intake.moveVoltage(12000);
  pros::delay(500);
  scraper.moveAbsolute(0, 200);
profileController.setTarget("Ball", true); //Go back to starting tile
  intake.moveVelocity(100);
  if(red){
  profileController.generatePath({
  Point{0_ft, 0_ft, 0_deg},
  Point{4_ft, 0_ft, 0_deg}},
  "botFlag"
);}
else{
  profileController.generatePath({
  Point{0_ft, 0_ft, 0_deg},
  Point{4_ft, 0_ft, 0_deg}},
  "botFlag"
);
}
 profileController.waitUntilSettled();
  profileController.removePath("Ball"); //Ball path removed here
  //profileController.removePath("Ball2"); //Ball path removed here

drive.setMaxVelocity(80);
//drive.moveDistance(-0.5_ft);
if(red){
  drive.turnAngle(-85_deg);
  drive.waitUntilSettled();
}else{
  drive.turnAngle(85_deg);
  drive.waitUntilSettled();
}
  intake.moveVelocity(0);
drive.setMaxVelocity(200);

  //Should shoot mid flags here
  //drive.moveDistance(0.5_ft);
  doubleShot();
  intake.moveVelocity(0);
  indexer.moveVelocity(0);
  drive.setMaxVelocity(200);
  //drive.moveDistance(4_ft);

  //drive.setMaxVelocity(150);
  if(red){
    drive.turnAngle(-5_deg);
    drive.waitUntilSettled();
  }else{
    drive.turnAngle(5_deg);
    drive.waitUntilSettled();
  }
  profileController.setTarget("botFlag");
  //drive.moveDistanceAsync(3.5_ft);
  //pros::delay(1500);
  //scraper.moveAbsolute(360, 200);
  //pros::delay(500);
  //scraper.moveAbsolute(0, 200);
  profileController.waitUntilSettled();
  //drive.waitUntilSettled();
  /*
  scraper.moveAbsolute(360, 200);
  pros::delay(500);
  scraper.moveAbsolute(0, 200);
*/
  profileController.setTarget("botFlag", true);
  profileController.waitUntilSettled();


  profileController.removePath("botFlag");
  drive.waitUntilSettled();

  drive.setMaxVelocity(80);
  if(red){
    drive.turnAngle(40_deg);
    drive.waitUntilSettled();
  }else{
    drive.turnAngle(-40_deg);
    drive.waitUntilSettled();
  }
  drive.setMaxVelocity(100);
  //drive.moveDistance(1.5_ft);

  drive.moveDistance(2_ft);
  //indexer.moveVelocity(200);

  //pros::delay(1000);
  scraper.moveAbsolute(360, 200);
  //drive.waitUntilSettled();
  pros::delay(300);

  drive.moveDistanceAsync(-2_ft);
  intake.moveVelocity(200);
  pros::delay(500);
  scraper.moveAbsolute(0, 200);
  drive.waitUntilSettled();

}
void autonomous() {

intake.moveVelocity(200);
//  profile.generatePath({Point{1_ft, 7ft, 0_deg}, Point{5_ft, 7_ft, 0_deg}}, "Cap"});
flywheel->setGearing(AbstractMotor::gearset::blue);

//flywheelControlTask((void*)on);
flywheel->moveVelocity(560);
front();
//backSimple();
//skills();
}

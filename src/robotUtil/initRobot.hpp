#pragma once
#include "main.h"

extern Motor intake;
extern Motor* flywheel;
extern Motor indexer;
extern Motor scraper;
extern ControllerButton doubleShotTest;
void doubleShotTask(void* enable);
void doubleShot();

void slowDoubleShot();

void scrape();
void flipCap();
void adjustScraper(void* enable);
extern ChassisControllerIntegrated drive;
extern AsyncMotionProfileController profileController;

extern pros::ADILineSensor flywheelSensor;
extern pros::ADIPotentiometer scraperPot;

extern float potError;
extern float potTarget;

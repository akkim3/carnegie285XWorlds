#pragma once
#include "main.h"

extern Motor intake;
extern Motor* flywheel;
extern Motor indexer;
extern Motor scraper;

void doubleShot();
extern ChassisControllerIntegrated drive;
extern AsyncMotionProfileController profileController;

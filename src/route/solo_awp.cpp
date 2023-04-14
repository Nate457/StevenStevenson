#include "../include/main.h"
#include "../globals/globals.hpp"
#include "../lib/movement.hpp"
#include "../lib/helper_functions.hpp"
#include "../lib/scoring.hpp"
#include "pros/vision.h"

using namespace pros;

void solo_awp() {
      // initial setup
    vector center = {};
    leveler.set_value(1);
    unsigned timeElapsed = 0;
    unsigned desiredSpeed = 2459;
    pros::Task regulate_shooting_speed(regulateFlywheel, &desiredSpeed);

    // shoot preloads and turn roller
    move_straight(-0.5, &center); delay(30); turn_rollerN(false); delay(30);
    pros::delay(25);


    //pick up next 3 discs and shoot them
    turn3(60, 15, 48.5, &center);
    intake=127;
    pros::delay(25);
    move_straight2(35.0,80, 3,3, &center);
    pros::delay(15);
    turn3(-44,44, 319.4, &center);
    pros::delay(15);
    shoot(500);
    desiredSpeed = 2865;
    intake = 127;
    turn3(44, -44, 40.4, &center);
    pros::delay(15);
    move_straight2(84.4,82,3,3, &center);
    pros::delay(15);
    turn3(-49,49, 273.4, &center);
    shoot(550);
    pros::delay(15);
    move_straight2(-2.4,-104,3,3, &center);
    pros::delay(15);
    turn_rollerN(false); pros::delay(50);


    regulate_shooting_speed.remove();
    regulate_shooting_speed = (pros::task_t)NULL;

}
#include "../include/main.h"
#include "../globals/globals.hpp"
#include "../lib/movement.hpp"
#include "../lib/helper_functions.hpp"
#include "../lib/scoring.hpp"
#include "pros/vision.h"

using namespace pros;

void far_auto() {
    // initial setup
    vector center = {};
    leveler.set_value(1);
    unsigned timeElapsed = 0;
    unsigned desiredSpeed = 2799;
    pros::Task regulate_shooting_speed(regulateFlywheel, &desiredSpeed);

    // turn roller
    move_straight2(-13.5, -65, 3, 2, &center);
    turn3(41, -64, 101.5, &center);
    move_straight2(-3.2, -55, 3, 2, &center);
    turn_rollerN(false); pros::delay(50);
    intake=127;
    move_straight2(12.6, 60, 3, 2, &center);
    pros::delay(1020);
    while (desiredSpeed != INT16_MAX) {
        delay(15);
    }
    desiredSpeed = 2799;
    shoot(550);
    desiredSpeed = 2525;
    intake=127;
    move_straight2(-9.5, -78, 3, 2, &center);
    turn3(-53, 53, 43, &center);
    pros::delay(50);
    move_straight2(61.2, 85, 3, 2, &center);
    move_straight2(-10.54, -85, 3, 2, &center);
    pros::delay(180);
    turn3(51, -51, 126.75, &center);
    shoot(490);
    desiredSpeed = 2445;
    intake=127;
    move_straight2(4.9, 81, 3, 2, &center);
    pros::delay(1180);
    shoot(410);

    regulate_shooting_speed.remove();
    regulate_shooting_speed = (pros::task_t)NULL;
 }
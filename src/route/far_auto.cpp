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
    unsigned desiredSpeed = 2595;
    pros::Task regulate_shooting_speed(regulateFlywheel, &desiredSpeed);

    // turn roller
    move_straight2(-10.8, -65, 3, 2, &center);
    pros::delay(15);
    turn3(39, -78, 101.5, &center);
    pros::delay(15);
    move_straight2(-2.8, -45, 3, 2, &center);
    pros::delay(15);
    turn_rollerN(false); pros::delay(30);
    intake=127;
    move_straight2(9.3, 71, 3, 2, &center);
    pros::delay(690);
    while (desiredSpeed != INT16_MAX) {
        delay(15);
    }
    desiredSpeed = 2595;
    pros::delay(300);
    shoot(540);
    desiredSpeed = 2545;
    intake=127;
    move_straight2(-8.0, -78, 3, 2, &center);
    pros::delay(30);
    turn3(-55, 55, 44.2, &center);
    pros::delay(20);
    move_straight2(62.1, 82, 3, 2, &center);
    pros::delay(20);
    move_straight2(-10.10, -82, 3, 2, &center);
    pros::delay(50);
    turn3(53, -53, 128.45, &center);
    pros::delay(20);
    shoot(410);
    desiredSpeed = 2455;
    intake=127;
    move_straight2(3.2, 75, 3, 2, &center);
    pros::delay(940);
    shoot(350);

    regulate_shooting_speed.remove();
    regulate_shooting_speed = (pros::task_t)NULL;
 }
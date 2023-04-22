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
    unsigned desiredSpeed = 2635;
    pros::Task regulate_shooting_speed(regulateFlywheel, &desiredSpeed);

    // turn roller
    move_straight2(-10.2, -65, 3, 2, &center);
    pros::delay(15);
    turn4(38, -85, 97.0, &center);
    pros::delay(15);
    move_straight2(-2.8, -45, 3, 2, &center);
    pros::delay(15);
    turn_rollerN(false); pros::delay(30);
    intake=127;
    move_straight2(7.7, 65, 3, 2, &center);
    pros::delay(790);
    while (desiredSpeed != INT16_MAX) {
        delay(15);
    }
    desiredSpeed = 2635;
    pros::delay(360);
    shoot(590);
    desiredSpeed = 2525;
    intake=127;
    move_straight2(-4.9, -65, 3, 2, &center);
    pros::delay(30);
    turn3(-64, 64, 42.4, &center);
    pros::delay(20);
    move_straight2(62.1, 82, 3, 2, &center);
    pros::delay(20);
    move_straight2(-9.85, -72, 3, 2, &center);
    pros::delay(50);
    turn3(64, -64, 127.5, &center);
    pros::delay(20);
    shoot(410);
    desiredSpeed = 2485;
    intake=127;
    center.desiredHeading = 125.5; 
    pros::delay(100);
    move_straight(3.3, &center);
    pros::delay(1040);
    shoot(350);

    regulate_shooting_speed.remove();
    regulate_shooting_speed = (pros::task_t)NULL;
 }
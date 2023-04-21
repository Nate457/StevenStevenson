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
    unsigned desiredSpeed = 2585;
    pros::Task regulate_shooting_speed(regulateFlywheel, &desiredSpeed);

    // turn roller
    move_straight2(-10.6, -65, 3, 2, &center);
    pros::delay(15);
    turn4(38, -85, 99.5, &center);
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
    desiredSpeed = 2585;
    pros::delay(360);
    shoot(560);
    desiredSpeed = 2525;
    intake=127;
    move_straight2(-4.9, -65, 3, 2, &center);
    pros::delay(30);
    turn3(-64, 64, 42.4, &center);
    pros::delay(20);
    move_straight2(62.1, 82, 3, 2, &center);
    pros::delay(20);
    move_straight2(-8.85, -82, 3, 2, &center);
    pros::delay(50);
    turn3(64, -64, 128.15, &center);
    pros::delay(20);
    shoot(410);
    desiredSpeed = 2485;
    intake=127;
    move_straight2(2.2, 75, 3, 2, &center);
    pros::delay(940);
    shoot(350);

    regulate_shooting_speed.remove();
    regulate_shooting_speed = (pros::task_t)NULL;
 }
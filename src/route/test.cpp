#include "../include/main.h"
#include "../globals/globals.hpp"
#include "../lib/movement.hpp"
#include "../lib/helper_functions.hpp"
#include "../lib/scoring.hpp"
#include "pros/vision.h"

using namespace pros;

void test() {
    // initial setup

    vector center = {};
    leveler.set_value(1);
    unsigned timeElapsed = 0;
    unsigned desiredSpeed = 2530;
    pros::Task regulate_shooting_speed(regulateFlywheel, &desiredSpeed);
    intake=127;
    move_straight2(36.6, 94, 3, 2, &center);
    pros::delay(15);
    turn3(69, -69, 45.6, &center);
    shoot(410);
    intake=127;
    turn3(75, -75, 199.2, &center);
    move_straight2(39.6, 90, 3, 2, &center);
    pros::delay(100);
    move_straight2(-39.6, -90, 3, 2, &center);
    turn3(-75, 75, 45.1, &center);
    shoot(410);
    intake = 127;
    turn3(65, -65, 133.1, &center);
    move_straight2(56.6, 85, 3, 2, &center);
}
//move_straight2(const double dist, const int baseVolt, const double accel, const double deccel, vector *pCenter)
//823
//1664

//423/360 rotations

//-1192
//
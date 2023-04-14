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
    unsigned desiredSpeed = 2830;
    pros::Task regulate_shooting_speed(regulateFlywheel, &desiredSpeed);
    intake=127;
    move_straight2(28.0, 71, 3, 2, &center);
}
//move_straight2(const double dist, const int baseVolt, const double accel, const double deccel, vector *pCenter)
//823
//1664

//423/360 rotations

//-1192
//
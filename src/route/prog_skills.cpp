#include "../include/main.h"
#include "../globals/globals.hpp"
#include "../lib/movement.hpp"
#include "../lib/helper_functions.hpp"
#include "../lib/scoring.hpp"
#include "pros/vision.h"

using namespace pros;

void prog_skills() {
    // initial setup
    vector center = {0,0,0};

    unsigned timeElapsed = 0;
    unsigned desiredSpeed = 2120;
    leveler.set_value(1);

    pros::Task regulate_shooting_speed(regulateFlywheel, &desiredSpeed);
// first shot

    // while (desiredSpeed != INT16_MAX) {
    //     delay(15);
    // }
    // desiredSpeed = 0;

    pros::delay(3400);
    shoot(310);
    pros::delay(400);
    shoot(580);
    pros::delay(400);
    shoot(580);
    pros::delay(400);
    shoot(580);
    turn(28,-28,30, &center);
    move_straight(-29, -58, &center);

    turn(-28, 28, 288, &center);
    move_straight(-3.8, -50, &center);
    move_straight(2.2, -35); delay(200); turn_rollerN(true); delay(200);

    move_straight(18.1, 50, &center);
    turn(28, -28, 13, &center);

    move_straight(-17.9, -50, &center);
    move_straight(2.2, -35); delay(200); turn_rollerN(true); delay(200);

    move_straight(8.5, 50, &center);
    turn(-23, 23, 335, &center);


    move_straight(79.5, 80, &center);
    turn(23, -23, 115, &center);
    move_straight(-11.4, -50, &center);
    move_straight(2.2, -25); delay(200); turn_rollerN(true); delay(200);

    move_straight(8.5, 50, &center);
    turn(22, -22, 181, &center);
    move_straight(-14.8, -40, &center);
    move_straight(1.7, -25); delay(200); turn_rollerN(true); delay(200);

    move_straight(8.5, 50, &center);
    turn(22, -22, 210.5, &center);
    move_straight(39.2, 50, &center);
    turn(-22, 22, 185, &center);
    pros::delay(1000);
    shoot(310);
    pros::delay(400);
    shoot(580);
    pros::delay(400);
    shoot(580);
    pros::delay(400);
    shoot(580);

    turn(22, -22, 205, &center);
    move_straight(-32.5, -50, &center);
    turn(-22, 22, 135, &center);

	expander1_piston.set_value(1);
	expander2_piston.set_value(1);
	side_piston.set_value(1);
	side2_piston.set_value(1);
	side3_piston.set_value(1);
	side4_piston.set_value(1);

    regulate_shooting_speed.remove();
    regulate_shooting_speed = (pros::task_t)NULL;


}
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
    unsigned desiredSpeed = 1565;
    pros::Task regulate_shooting_speed(regulateFlywheel, &desiredSpeed);

    // shoot preloads and turn roller
    move_straight(-0.8, &center); delay(40); turn_rollerN(false); delay(40);
    move_straight(1.0, 60.0, &center);
    intake=127;


     while (desiredSpeed != INT16_MAX) {
        delay(15);
    }

    //pick up next 3 discs and shoot them
    desiredSpeed = 2494; 
    turn(28, -28, 46, &center);
    pros::delay(60);
    move_straight(27.0,64, &center);
    pros::delay(120);

    // delay(50);
    
    // // shoot preloads and turn roller
    // turn(-50, 50, -3, &center);
    // flywheel_piston.set_value(1); delay(800); flywheel_piston.set_value(0);
    // pros::delay(50);
    // turn(50, -50, 0 - center.heading, &center);
    // delay(50);

    // move_straight(60); turn_roller(100); delay(100);
    // move_straight(-5.0, &center);
    //track_time.remove();
    //master.print(0, 0, "%d", timeElapsed);
    // pick up next 3 discs and shoot them
    // shootSpeed = 2000; intake=127;
    // turn(-25, 25, -124, &center);
    // move_straight(60.0, 22, &center);
    // pros::delay(20);
    
    turn(-28,28, 334.0, &center);
    pros::delay(50);
    move_straight(1.0,  64.0, &center);
    pros::delay(80);
    shoot(490);
    desiredSpeed = 2878; 
    intake = 127;
    turn(28,-28, 47.0, &center);
    move_straight(38.5, 64.0, &center);
    turn(-28,28, 303.1, &center);
    shoot(490);
    turn(-31,31, 225.9, &center);
    move_straight(-15.9, -69.0, &center);
    turn(31,-21, 271, &center);
    intake = 0;
    move_straight(0.39,-58); delay(50); turn_rollerN(false); delay(50);


    // desiredSpeed = 2720;
    // move_straight(1, 61.0, &center);
    // turn(-29,29,90,&center);
    // //pickup discs next to the goal
    // intake=127;
    // move_straight(43.0, 80.0, &center);
    // move_straight(-40.0,-61.0,&center);
    // turn(29,-29,135.0,&center);
    // move_straight(-5.0,-61.0,&center);
    // shoot(800);

    // cleanup program

    regulate_shooting_speed.remove();
    regulate_shooting_speed = (pros::task_t)NULL;
}
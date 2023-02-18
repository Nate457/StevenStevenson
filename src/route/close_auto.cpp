#include "../include/main.h"
#include "../globals/globals.hpp"
#include "../lib/movement.hpp"
#include "../lib/helper_functions.hpp"
#include "../lib/scoring.hpp"
#include "pros/vision.h"

using namespace pros;

void close_a() {
      // initial setup
    vector center = {};
    leveler.set_value(1);
    unsigned timeElapsed = 0;
    unsigned desiredSpeed = 2635;
    pros::Task regulate_shooting_speed(regulateFlywheel, &desiredSpeed);

    // shoot preloads and turn roller
    move_straight(-0.8, &center); delay(100); turn_rollerN(false); delay(100);
    move_straight(2.0, 60.0, &center);
    intake=127;
    move_straight(3.5,  61.0, &center);
    turn(-36, 36, 355.5, &center);

     while (desiredSpeed != INT16_MAX) {
        delay(15);
    }
    desiredSpeed = 2635;

    pros::delay(100);
    shoot(450);
    

    intake = 127;
    move_straight(-2.4,-59, &center);


    //pick up next 3 discs and shoot them
    desiredSpeed = 2465; 
    turn(35, -35, 42, &center);
    pros::delay(60);
    move_straight(23.0,64, &center);
    pros::delay(280);

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
    
    turn(-37,37, 335.2, &center);
    pros::delay(50);
    move_straight(1.8,  51.0, &center);
    pros::delay(80);
    shoot(410);
    intake = 127;
    pros::delay(380);
    move_straight(1.3,  38.0, &center);
    pros::delay(880);
    shoot(410);

    regulate_shooting_speed.remove();
    regulate_shooting_speed = (pros::task_t)NULL;

}
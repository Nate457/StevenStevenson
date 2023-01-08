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

    unsigned timeElapsed = 0;
    unsigned desiredSpeed = 2900;
    pros::Task regulate_shooting_speed(regulateFlywheel, &desiredSpeed);

    // shoot preloads and turn roller
    move_straight(-1.5, &center); delay(200); turn_rollerN(false); delay(200);
    move_straight(2.0, &center);
    intake=127;
    move_straight(6.9,  53.0, &center);
    move_straight(-2.3,  -35.0, &center);
    move_straight(2.0,  35.0, &center);

     while (desiredSpeed != INT16_MAX) {
        delay(15);
    }

    desiredSpeed = 2900;
    pros::delay(450);
    shoot(210);
    pros::delay(50);
    

    intake = 127;
    move_straight(-6.5,-41, &center);


    //pick up next 3 discs and shoot them
    desiredSpeed = 2900; 
    turn(23, -23, 55, &center);
    pros::delay(100);
    move_straight(36.5,41, &center);
    pros::delay(310);

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
    
    turn(-35,35, 343.4, &center);
    move_straight(2.0, &center);
    pros::delay(500);
    shoot(250);
    move_straight(5.0, &center);
    move_straight(-2.3,  -35.0, &center);
    move_straight(2.0,  35.0, &center);
    pros::delay(666);
     flywheel_piston.set_value(1);
    pros::delay(240); 
    flywheel_piston.set_value(0);
    pros::delay(340); 
    flywheel_piston.set_value(1);
    pros::delay(240); 
    flywheel_piston.set_value(0);
    //get 3 discs from low zone
    // turn(0,-30,0,&center);
    // move_straight(45,50,&center);
    // move_straight(-45,-50,&center);
    // turn(-25,25,315,&center);
    // flywheel_piston.set_value(1); delay(1300); flywheel_piston.set_value(0);



    // turn(-35,35, 232,&center);
    // pros::delay(80);
    
    // // pick up stack of 3 discs and shoot them (maybe)
    // move_straight(75.0, 35, &center);
    // turn(25,-25, 308, &center);
    // pros::delay(80);
    // flywheel_piston.set_value(1); delay(1200); flywheel_piston.set_value(0);
    // turn(-25,25, 239, &center);
    // pros::delay(80);

    // // turn 2nd roller
    // pros::delay(100);
    // // move_straight(75.0, 35, &center);
    // // pros::delay(80);
    // // turn(35,-35, 270, &center);
    // pros::delay(80);
    // move_straight(60); turn_roller(100);


   
    regulate_shooting_speed.remove();
 
    master.print(0, 0, "%d", timeElapsed);

}
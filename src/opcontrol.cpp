#include "../include/main.h"
#include "globals/globals.hpp"
#include "pros/misc.h"
#include "lib/movement.hpp"
#include "lib/scoring.hpp"

void opcontrol() {
	unsigned shootingSpeed = 1900;
	pros::Task regulateFlywheelSpeed(regulateFlywheel_o, &shootingSpeed);
	leveler.set_value(0);
			expander1_piston.set_value(0);
			expander2_piston.set_value(0);
			side_piston.set_value(0);
			side2_piston.set_value(0);
			side3_piston.set_value(0);
			side4_piston.set_value(0);
			side3_piston.set_value(0);
			side4_piston.set_value(0);

	indexer = 0;

	flywheel_piston.set_value(0);
	int intake_state=1;
	int flywheel_state = 1;
	while (true) {
		int power = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
		int turnRate = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X)*-1;

		move(power - turnRate, power + turnRate);
		int auto_fire = 0;


		if(master.get_digital(DIGITAL_L1))
		{
		indexer = -127;
		}
		else if(master.get_digital(DIGITAL_L2))
		{
		indexer = 127;
		}
		else{
			indexer = 0;
		}

		




	if(master.get_digital_new_press(DIGITAL_R2))
	{
			leveler.set_value(1);
		}
	if(master.get_digital_new_press(DIGITAL_R1))
	{
			leveler.set_value(0);
		}

		if (flywheel_state == 1){
		}
		else{
		flywheel = 0;
		shootingSpeed = 0;
		}
		if(master.get_digital_new_press(DIGITAL_UP) && master.get_digital (DIGITAL_DOWN) && master.get_digital (DIGITAL_RIGHT) && master.get_digital (DIGITAL_LEFT))
		{
			expander1_piston.set_value(1);
			pros::delay(20);
			expander2_piston.set_value(1);
			pros::delay(20);
			side_piston.set_value(1);
			pros::delay(20);
			side2_piston.set_value(1);
			pros::delay(20);
			side3_piston.set_value(1);
			pros::delay(20);
			side4_piston.set_value(1);
			pros::delay(20);
			side3_piston.set_value(1);
			pros::delay(20);
			side4_piston.set_value(1);
			pros::delay(70);
			flywheel_state = 0;
		}
	}
}
#include "../include/main.h"
#include "globals/globals.hpp"
#include "pros/misc.h"
#include "lib/movement.hpp"
#include "lib/scoring.hpp"

void opcontrol() {
	unsigned shootingSpeed = 2178;
	pros::Task regulateFlywheelSpeed(regulateFlywheel_o, &shootingSpeed);
	expander1_piston.set_value(0);
	expander2_piston.set_value(0);
	leveler.set_value(1);
	indexer = 0;

	flywheel_piston.set_value(0);
	int intake_state=1;
	int flywheel_state = 1;
	while (true) {
		int power = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
		int turnRate = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X)*-1;

		move(power - turnRate, power + turnRate);
		int auto_fire = 0;
		if(master.get_digital_new_press(DIGITAL_R1))
		{
			auto_fire = 1;
			flywheel_piston.set_value(1);
			pros::delay(245);
			flywheel_piston.set_value(0);
			pros::delay(215);
			flywheel_piston.set_value(1);
			pros::delay(245);
			flywheel_piston.set_value(0);
			pros::delay(215);
			flywheel_piston.set_value(1);
			pros::delay(245);
			flywheel_piston.set_value(0);
			auto_fire = 0;
		}
		else if (auto_fire == 0)
{
		if(master.get_digital(DIGITAL_R2))
		{
			flywheel_piston.set_value(1);
			pros::delay(180);
		}
		else if (master.get_digital(DIGITAL_L2) == 0)
		{
			flywheel_piston.set_value(0);
		}
}
		if(master.get_digital(DIGITAL_L1))
		{
		indexer = -127;
		}
		else if(master.get_digital(DIGITAL_L2))
		{
		indexer = 0;
		}
		else{
			indexer = 127;
		}



	if(master.get_digital_new_press(DIGITAL_X))
	{
			leveler.set_value(1);
		}
	if(master.get_digital_new_press(DIGITAL_Y))
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
			expander2_piston.set_value(1);
			side_piston.set_value(1);
			side2_piston.set_value(1);
			regulateFlywheelSpeed.remove();
			pros::delay(500);
			flywheel_state = 0;
		}
		else if(master.get_digital_new_press(DIGITAL_A) && master.get_digital (DIGITAL_B) && master.get_digital (DIGITAL_X) && master.get_digital (DIGITAL_Y))
		{
			side_piston.set_value(1);
			side2_piston.set_value(1);
			regulateFlywheelSpeed.remove();
			pros::delay(500);
			flywheel_state = 0;
		}
		else{
			expander1_piston.set_value(0);
			expander2_piston.set_value(0);
			side_piston.set_value(0);
			side2_piston.set_value(0);
		}
	}
}
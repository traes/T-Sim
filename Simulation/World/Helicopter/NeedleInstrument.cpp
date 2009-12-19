#include "NeedleInstrument.h"

NeedleInstrument::NeedleInstrument(){
	value = 0.0f;
	min_value = 0.0f;
	max_value = 100.0f;
	max_angle = 360.0f;
	mark_delta_value = 10.0f;
	number_of_marks = (int)(max_value/mark_delta_value);
	mark_delta_angle = max_angle / (float)number_of_marks;
	neutral_orientation = 0.0f;
	needles.push_back(Needle());
}

float NeedleInstrument::get_angle(float value){
	return (value/max_value) * max_angle;

}


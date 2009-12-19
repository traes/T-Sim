#include "AirspeedIndicator.h"

AirspeedIndicator::AirspeedIndicator(){
	max_value = 100.0f;
	mark_delta_value = 10.0f;
	// create color indications
	color_indications.push_back(ColorIndication());
	color_indications.push_back(ColorIndication());
	color_indications.push_back(ColorIndication());
	ColorIndication* green_speed = &(color_indications[0]);
	ColorIndication* yellow_speed = &(color_indications[1]);
	ColorIndication* red_speed = &(color_indications[2]);
	// set values
	green_speed->begin_value = 0.0f;
	green_speed->end_value = 70.0f;
	yellow_speed->begin_value = 70.0f;
	yellow_speed->end_value = 90.0f;
	red_speed->begin_value = 90.0f;
	red_speed->end_value = 100.0f;
	// set colors
	green_speed->green = 1.0f;
	yellow_speed->red = 1.0f;
	yellow_speed->green = 1.0f;
	yellow_speed->blue = 0.5f;
	red_speed->red = 1.0f;
}	

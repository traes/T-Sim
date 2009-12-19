#include "RPMIndicator.h"

RPMIndicator::RPMIndicator(){
	max_value = 400.0f;
	mark_delta_value = 50.0f;
	// create color indications
	color_indications.push_back(ColorIndication());
	color_indications.push_back(ColorIndication());
	color_indications.push_back(ColorIndication());
	ColorIndication* green_speed = &(color_indications[0]);
	ColorIndication* yellow_speed = &(color_indications[1]);
	ColorIndication* red_speed = &(color_indications[2]);
	// set values
	green_speed->begin_value = 0.0f;
	green_speed->end_value = 340.0f;
	yellow_speed->begin_value = 340.0f;
	yellow_speed->end_value = 360.0f;
	red_speed->begin_value = 360.0f;
	red_speed->end_value = 400.0f;
	// set colors
	green_speed->green = 1.0f;
	yellow_speed->red = 1.0f;
	yellow_speed->green = 1.0f;
	yellow_speed->blue = 0.5f;
	red_speed->red = 1.0f;

}	

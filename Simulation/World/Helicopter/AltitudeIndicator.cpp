#include "AltitudeIndicator.h"

AltitudeIndicator::AltitudeIndicator(){
	max_value = 100.0f;
	mark_delta_value = 10.0f;
	needles.push_back(Needle());
	needles[0].scale = 1.0f;
	needles[1].scale = 0.1f;
	needles[1].length /= 2.0f;
	needles[1].width *= 2.0f;
}	

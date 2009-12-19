#ifndef NEEDLE_INSTRUMENT_H
#define NEEDLE_INSTRUMENT_H

#include <vector>
#include "Instrument.h"
#include "Needle.h"
#include "ColorIndication.h"

class NeedleInstrument : public Instrument {
	public:
		NeedleInstrument();
		std::vector<Needle> needles;
		std::vector<ColorIndication> color_indications;
		float value;
		float min_value;
		float max_value;
		float max_angle;
		float mark_delta_value;
		float mark_delta_angle;
		int number_of_marks;
		float neutral_orientation;
		float get_angle(float value);
};		

#endif

#ifndef COMPASS_H
#define COMPASS_H

#include "Instrument.h"

class Compass : public Instrument {
	public:
		Compass();
		float heading;
};

#endif

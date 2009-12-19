#ifndef ARTIFICIAL_HORIZON_H
#define ARTIFICIAL_HORIZON_H

#include "Instrument.h"

class ArtificialHorizon : public Instrument {
	public:
		ArtificialHorizon();
		float roll;
		float pitch;
};

#endif

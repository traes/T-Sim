#ifndef INSTRUMENT__VIEWER_H
#define INSTRUMENT__VIEWER_H

#include "Instrument.h"
#include "NumberRepresentation.h"

class InstrumentRepresentation {
	public:	
		InstrumentRepresentation();
		void show(Instrument* instrument);
		float width;
		float height;
	protected:
		NumberRepresentation number_representation;
		void show_background(Instrument* instrument);
};

#endif

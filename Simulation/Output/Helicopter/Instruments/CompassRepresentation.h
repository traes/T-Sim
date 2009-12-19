#ifndef COMPASS__REPRESENTATION_H
#define COMPASS__REPRESENTATION_H

#include "Compass.h"
#include "InstrumentRepresentation.h"

class CompassRepresentation : public InstrumentRepresentation {
	public:	
		CompassRepresentation();
		void show(Compass* compass);
		float width;
		float height;
	private:
		void show_directions();
};

#endif

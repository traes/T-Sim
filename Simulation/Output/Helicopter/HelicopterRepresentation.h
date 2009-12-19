#ifndef HELICOPTER__VIEWER_H
#define HELICOPTER__VIEWER_H

#include "Helicopter.h"
#include "RotorRepresentation.h"

class HelicopterRepresentation {
	public:
		HelicopterRepresentation();
		void show(Helicopter* helicopter);
	private:
		RotorRepresentation rotor_representation;
};

#endif

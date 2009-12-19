#ifndef HELICOPTER_H
#define HELICOPTER_H

#include "Vector3D.h"
#include "Rotor.h"
#include "InstrumentPanel.h"

class Helicopter {
	public:
		Helicopter();
		bool crashed;
		// instrument
		InstrumentPanel instrument_panel;
		// controls
		float cyclic_x;
		float cyclic_z;
		float collective;
		float throttle;
		float pedals;
		// physical properties
		float thrust;
		float mass;
		Rotor main_rotor;
		Rotor tail_rotor;
		Vector3D position;
		Vector3D velocity;
		Vector3D acceleration;
		Vector3D orientation;
};		

#endif

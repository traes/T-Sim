#ifndef SIMPLE_FLIGHT_MODEL_H
#define SIMPLE_FLIGHT_MODEL_H

#include <math.h>
#include "Helicopter.h"
#include "Rotor.h"
#include "InstrumentPanel.h"
#include "Conversions.h"

class SimpleFlightModel {
	public:
		SimpleFlightModel();
		void update(Helicopter* helicopter,float dt);
	private:
		void apply_controls(Helicopter* helicopter,float dt);
		void update_orientation(Helicopter* helicopter,float dt);
		void update_position(Helicopter* helicopter,float dt);
		void update_instruments(Helicopter* helicopter,float dt);
		void update_crashed(Helicopter* helicopter,float dt);
};

#endif

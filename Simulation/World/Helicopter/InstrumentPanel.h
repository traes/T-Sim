#ifndef INSTRUMENT_PANEL_H
#define INSTRUMENT_PANEL_H

#include <vector>

#include "ClimbIndicator.h"
#include "ArtificialHorizon.h"
#include "AirspeedIndicator.h"
#include "RPMIndicator.h"
#include "AltitudeIndicator.h"
#include "Compass.h"
#include "AirPressureIndicator.h"

class InstrumentPanel {
	public:
		InstrumentPanel();
		~InstrumentPanel();
		// Instruments 
		ClimbIndicator climb_indicator;
		ArtificialHorizon artificial_horizon;
		AirspeedIndicator airspeed_indicator;
		RPMIndicator rpm_indicator;
		AltitudeIndicator altitude_indicator;
		Compass compass;
		AirPressureIndicator air_pressure_indicator;
};		

#endif

#include "InstrumentPanel.h"

InstrumentPanel::InstrumentPanel(){
	// Instruments
	climb_indicator = ClimbIndicator();
	artificial_horizon = ArtificialHorizon();
	airspeed_indicator = AirspeedIndicator();
	rpm_indicator = RPMIndicator();
	altitude_indicator = AltitudeIndicator();
	compass = Compass();
	air_pressure_indicator = AirPressureIndicator();
}

InstrumentPanel::~InstrumentPanel(){

}

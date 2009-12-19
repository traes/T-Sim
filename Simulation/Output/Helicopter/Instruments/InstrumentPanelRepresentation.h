#ifndef INSTRUMENT_PANEL__REPRESENTATION_H
#define INSTRUMENT_PANEL__REPRESENTATION_H

#include "InstrumentPanel.h"
#include "ArtificialHorizonRepresentation.h"
#include "CompassRepresentation.h"
#include "NeedleInstrumentRepresentation.h"

/*

Robinson R22 instrument panel:

           (+) ^ Y
               :
    ___________:___________
    \          :          / 
     \  <0> <1>:<2> <3>  /
   ............:..............> X
       \  <4> <5> <6>  /     (+)
        \______:______/	
               :

0: climb indicator
1: artificial horizon
2: airspeed indicator
3: rpm indicator
4: altitude indicator
5: compass
6: air pressure indicator

*/


class InstrumentPanelRepresentation {
	public:
		InstrumentPanelRepresentation();
		void show(InstrumentPanel* instrument_panel);
		float width;
		float height;
		float viewing_distance;
	private: 
		ArtificialHorizonRepresentation artificial_horizon_representation;
		CompassRepresentation compass_representation;
		NeedleInstrumentRepresentation needle_instrument_representation;
		void show_panel_background(InstrumentPanel* instrument_panel);
		void show_instruments(InstrumentPanel* instrument_panel);
		void show_lights(InstrumentPanel* instrument_panel);
		void show_warning_light();
};

#endif

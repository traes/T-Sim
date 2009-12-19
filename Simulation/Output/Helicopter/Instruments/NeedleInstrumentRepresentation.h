#ifndef NEEDLE_INSTRUMENT__REPRESENTATION
#define NEEDLE_INSTRUMENT__REPRESENTATION

#include "InstrumentRepresentation.h"
#include "NeedleRepresentation.h"
#include "NeedleInstrument.h"
#include "ColorIndication.h"

class NeedleInstrumentRepresentation : public InstrumentRepresentation {
	public:
		NeedleInstrumentRepresentation();
		void show(NeedleInstrument* instrument);
	protected:
		NeedleRepresentation needle_representation;
		void show_needle(NeedleInstrument* instrument);
		void show_marks(NeedleInstrument* instrument);
		void show_values(NeedleInstrument* instrument);
		void show_color_indications(NeedleInstrument* instrument);
};		


#endif

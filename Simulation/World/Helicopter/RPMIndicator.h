#ifndef RPM_INDICATOR_H
#define RPM_INDICATOR_H

#include "NeedleInstrument.h"

class RPMIndicator : public NeedleInstrument {
	public:
		RPMIndicator();
		float engine_rpm;
		float rotor_rpm;
		Needle* engine_rpm_needle;
		Needle* rotor_rpm_needle;
};		

#endif

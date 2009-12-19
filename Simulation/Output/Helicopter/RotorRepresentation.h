#ifndef ROTOR__VIEWER_H
#define ROTOR__VIEWER_H

#include "Rotor.h"

class RotorRepresentation{
	public:
		RotorRepresentation();
		void show(Rotor* rotor);
	private:
	 	float min_rpm_for_disk;
		void show_single_blade(Rotor* rotor);
		void show_rotor_as_blades(Rotor* rotor);
		void show_rotor_as_disk(Rotor* rotor);
};

#endif

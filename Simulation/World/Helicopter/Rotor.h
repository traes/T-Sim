#ifndef ROTOR_H
#define ROTOR_H

#include "Vector3D.h"
#include <vector>

class Rotor {
	public:
		Rotor();
		Rotor(int b,float c,float r_h,float r_t);
		int b; // number of blades
		float c; // chord of each blade (m)
		float r_h; // (Hub) distance shaft -> begin blade (m)
		float r_t; // distance shaft -> blade tip (m)
		float rpm; // rounds per minute
		float max_rpm;
		float theta;
		Vector3D orientation; // orientation wrt. shft
		void update(float dt);
};
#endif

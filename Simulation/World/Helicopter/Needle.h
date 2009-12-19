#ifndef NEEDLE_H
#define NEEDLE_H

#include "Vector3D.h"

class Needle {
	public:
		Needle();
		Vector3D origin;
		float length;
		float width;
		float scale;
		float get_angle(float value);
};		

#endif

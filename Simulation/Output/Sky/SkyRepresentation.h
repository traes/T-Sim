#ifndef SKY_REPRESENTATION_H
#define SKY_REPRESENTATION_H

#include <vector>
#include "Sky.h"
#include "CloudRepresentation.h"
#include "Vector3D.h"

class SkyRepresentation {
	public:
		SkyRepresentation();
		void show(Sky* sky,Vector3D* position);
	private:
		void show_air(Sky* sky,Vector3D* position);
		void show_clouds(Sky* sky,Vector3D* position);
		CloudRepresentation cloud_representation;
};

#endif

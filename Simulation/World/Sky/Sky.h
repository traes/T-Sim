#ifndef SKY_H
#define SKY_H

#include <vector>
#include "Cloud.h"
#include "Vector3D.h"

class Sky {
	public:
		Sky();
		std::vector<Cloud> clouds;
};

#endif

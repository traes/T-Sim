#ifndef TERRAIN_HOUSE_H
#define TERRAIN_HOUSE_H

#include "Color.h"

class TerrainHouse {
	public:
		TerrainHouse();
		float center_x;
		float center_z;
		float width;
		float length;
		float base_height;
		float wall_height; // from ground to top of wall
		float roof_height; // from top of wall to rooftop
		Color roof_color;
		Color wall_color;
};		

#endif

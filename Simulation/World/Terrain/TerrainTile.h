#ifndef TERRAIN_TILE_H
#define TERRAIN_TILE_H

#include <vector>
#include "Color.h"
#include "TerrainHouse.h"
#include "TerrainTree.h"

class TerrainTile {
	public:
		TerrainTile();
		TerrainTile(float center_x,float center_z,float dimension);
		float center_x;
		float center_z;
		float dimension;
		float height(float x,float z);
		Color base_color;
		Color color(float x,float z);
		bool flat;
		std::vector<TerrainHouse*> create_houses();
		std::vector<TerrainTree*> create_trees();
		void delete_houses();
		void delete_trees();
	private:	
		std::vector<TerrainHouse*> houses;
		std::vector<TerrainTree*> trees;
};

#endif

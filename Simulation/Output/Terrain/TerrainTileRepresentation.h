#ifndef TERRAIN_TILE__VIEWER_H
#define TERRAIN_TILE__VIEWER_H

#include "TerrainTile.h"
#include "TerrainHouseRepresentation.h"
#include "TerrainTreeRepresentation.h"

class TerrainTileRepresentation {
	public:
		TerrainTileRepresentation();
		void show(TerrainTile* tile,float step);
		bool wireframe;
	private:
		void show_terrain(TerrainTile* tile,float step);
		void show_houses(TerrainTile* tile);
		void show_trees(TerrainTile* tile);
		TerrainHouseRepresentation house_representation;
		TerrainTreeRepresentation tree_representation;
};

#endif

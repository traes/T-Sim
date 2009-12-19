#ifndef TERRAIN_TILE_STORE_H
#define TERRAIN_TILE_STORE_H

#include <map>
#include <vector>
#include "TerrainTile.h"
#include "Vector3D.h"

class TerrainTileStore {
	public:
		TerrainTileStore();
		void add(TerrainTile tile);
		TerrainTile* get(float x,float z);
		std::vector<TerrainTile*> get_environment(Vector3D* position,float surrounding);
		TerrainTile default_tile;
		void delete_temp();
	private:	
		int nearest_center(float coordinate);
		// regulare tiles
		std::map<int,std::map<int,TerrainTile> > tiles;
		std::map<int,std::map<int,TerrainTile> >::iterator iter_x;
		std::map<int,TerrainTile>::iterator iter_z;
		std::map<int,TerrainTile>* map_z;
		// default tiles
		TerrainTile* create_temp_tile(float x,float z);
		std::vector<TerrainTile*> temp_tiles;
		std::vector<TerrainTile*>::iterator iter_temp_tiles;
};

#endif

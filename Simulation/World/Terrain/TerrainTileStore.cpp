#include <map>
#include <math.h>
#include <iostream>
#include "TerrainTileStore.h"
#include "TerrainTile.h"

TerrainTileStore::TerrainTileStore(){
	default_tile = TerrainTile();
	map_z = 0;
}

void TerrainTileStore::add(TerrainTile tile){
	int x = (int)tile.center_x;
	int z = (int)tile.center_z;
	tiles[x][z] = tile;
}

TerrainTile* TerrainTileStore::get(float x,float z){
	TerrainTile* result = 0;
	int x_nearest_center = nearest_center(x);
	int z_nearest_center = nearest_center(z);
	// look for tile with given center
	iter_x = tiles.find(x_nearest_center);
	if (iter_x != tiles.end()){
		map_z = &(iter_x->second);
		iter_z = map_z->find(z_nearest_center);
		if (iter_z != map_z->end())
			result = &(iter_z->second);	
		map_z = 0; // reset pointer	
	};
	// return default tile when no tiles are found
	if (!result){
		result = create_temp_tile((float)x_nearest_center,(float)z_nearest_center);
	};
	return result;
}

void TerrainTileStore::delete_temp(){
	for(iter_temp_tiles = temp_tiles.begin();iter_temp_tiles != temp_tiles.end();iter_temp_tiles++){
		delete *iter_temp_tiles;
	};
	temp_tiles.clear();
}

TerrainTile* TerrainTileStore::create_temp_tile(float x,float z){
	TerrainTile* tile = new TerrainTile();
	tile->dimension = 1000.0f;
	tile->center_x = x;
	tile->center_z = z;
	temp_tiles.push_back(tile);
	return tile;
}

std::vector<TerrainTile*> TerrainTileStore::get_environment(Vector3D* position,float viewing_distance){
	float x = position->x;
	float y = position->y;
	float z = position->z;
	
	int dimension = (int)default_tile.dimension; // m
	
	std::vector<TerrainTile*> result;
	int min_x = (int)(x - viewing_distance);
	int max_x = (int)(x + viewing_distance);
	int min_z = (int)(z - viewing_distance);
	int max_z = (int)(z + viewing_distance);
	for(int x = min_x; x <= max_x; x += dimension){
		for(int z = min_z; z <= max_z; z += dimension){
			result.push_back(get(x,z));	
		};
	};
	return result;
}

int TerrainTileStore::nearest_center(float coordinate){
	int tile_dimension = (int) default_tile.dimension; // m
	float border = tile_dimension / 2;
	int half_tile_index = (int)trunc(coordinate/border);
	if ((half_tile_index % 2) != 0)
		(half_tile_index > 0) ? half_tile_index++ : half_tile_index--;
	int closest_center = (int)(tile_dimension * (half_tile_index / 2));
	return closest_center;
}

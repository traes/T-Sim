#include <math.h>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include "TerrainRepresentation.h"

TerrainRepresentation::TerrainRepresentation(){
	tile_representation = TerrainTileRepresentation();
}


void TerrainRepresentation::show(Terrain* terrain,Vector3D* position){
	float x = position->x;
	float z = position->z;
	float y = position->y;
	float initial_viewing_distance = 2000.0f;
	float initial_grid_step = 100.0f;
	float viewing_distance = initial_viewing_distance; 
	float grid_step = initial_grid_step;
	float tile_dimension = 1000.0f;
	float altitude_factor = 5 * (int) round(y/1000.0);
	if (altitude_factor > 1){
		viewing_distance = initial_viewing_distance * altitude_factor; // more tiles
		grid_step = initial_grid_step * altitude_factor; // tiles less detailed
		if (grid_step > tile_dimension)
			grid_step = tile_dimension;
		if (viewing_distance < initial_viewing_distance)
			viewing_distance = initial_viewing_distance;
		if (grid_step < initial_grid_step)
			grid_step = initial_grid_step;
	};
	std::vector<TerrainTile*>::iterator tiles_iter;
	std::vector<TerrainTile*> environment = terrain->tiles.get_environment(position,viewing_distance);
	int tiles = 0;
	for(tiles_iter = environment.begin();tiles_iter != environment.end(); tiles_iter++){
		TerrainTile* tile = *tiles_iter;
		tile_representation.show(tile,grid_step);
		tiles++;
	}
	terrain->tiles.delete_temp();
}

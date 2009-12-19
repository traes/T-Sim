#include <iostream>
#include <vector>
#include <math.h>
#include <cassert>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Terrain.h"

Terrain::Terrain() {
	float tile_dimension = 1000.0f;
	// tiles
	tiles.add(TerrainTile(0.0f,0.0f,tile_dimension)); 
	// default tile
	TerrainTile default_tile = TerrainTile();
	default_tile.flat = 0;
	default_tile.dimension = tile_dimension;
	default_tile.base_color = Color(0,1,0);
	tiles.default_tile = default_tile;
}

float Terrain::height(float x,float z){
	TerrainTile *tile = tiles.get(x,z);	
	return tile->height(x,z);
}


#ifndef TERRAIN_VIEWER_H
#define TERRAIN_VIEWER_H

#include "Terrain.h"
#include "Vector3D.h"
#include "TerrainTileRepresentation.h"

class TerrainRepresentation {
	public:
		TerrainRepresentation();
		void show(Terrain* terrain,Vector3D* position);
		bool wireframe;
	private:
		TerrainTileRepresentation tile_representation;

};

#endif

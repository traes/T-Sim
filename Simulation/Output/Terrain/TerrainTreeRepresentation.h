#ifndef TERRAIN_TREE_REPRESENTATION_H
#define TERRAIN_TREE_REPRESENTATION_H

#include "TerrainTree.h"

class TerrainTreeRepresentation{
	public:
		TerrainTreeRepresentation();
		void show(TerrainTree* tree);
	private:
		void show_trunk(TerrainTree* tree);
		void show_leafs(TerrainTree* tree);
};		

#endif

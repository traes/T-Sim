#include <iostream>
#include <stdlib.h>
#include <math.h>

#include "TerrainTile.h"

TerrainTile::TerrainTile(){
	center_x = 0;
	center_z = 0;
	dimension = 0;
	flat = 1;
	base_color = Color(0.0f,1.0f,0.0f);
}

TerrainTile::TerrainTile(float center_x_arg,float center_z_arg,float dimension_arg){
	center_x = center_x_arg;
	center_z = center_z_arg;
	dimension = dimension_arg;
	flat = 1;
	base_color = Color(0.0f,1.0f,0.0f);
}

float TerrainTile::height(float x,float z){
	float result = 0;
	(flat) ? result = 0 : result = sin(x * (z + 1850)) * 2;
	return result;
}

Color TerrainTile::color(float x,float z){
	float green = sin((x + 1375) * (z + 2468) + 137) / 20; 
	float red = cos((x + 2468) * (z + 1375) + 246) * 0.8; 
	return Color(red,green + 0.8f,0.0f);
}

std::vector<TerrainHouse*> TerrainTile::create_houses(){
	for(int number_of_houses = 0; number_of_houses < 5; number_of_houses++){
		// distance from center of tile
		float delta_x = ((number_of_houses * 1375) + 246) % (int) dimension/2; 
		float delta_z = ((number_of_houses * 2468) + 137) % (int) dimension/2; 
		TerrainHouse* house = new TerrainHouse();
		house->center_x = center_x + delta_x;
		house->center_z = center_z + delta_z;
		house->base_height = height(house->center_x,house->center_z);
		house->roof_color.red = 0.5 + sin(delta_x)/2;
		house->wall_color.red = 0.75 + sin(delta_x)/4;
		house->wall_color.green = 0.75 + sin(delta_x)/4;
		house->wall_color.blue = 0.75 + sin(delta_z)/4;
		houses.push_back(house);
	};
	return houses;
}

void TerrainTile::delete_houses(){
	std::vector<TerrainHouse*>::iterator iter;
	for (iter=houses.begin();iter != houses.end();iter++){
		delete *iter;
	};
	houses.clear();
}

std::vector<TerrainTree*> TerrainTile::create_trees(){
	for(int number_of_trees = 0; number_of_trees < 30; number_of_trees++){
		// distance from center of tile
		float delta_x = ((number_of_trees * 175) + 1397) % (int) dimension/2; 
		float delta_z = ((number_of_trees * 268) + 2427) % (int) dimension/2; 
		TerrainTree* tree = new TerrainTree();
		tree->color.green = 0.75 + sin(delta_x)/4;
		tree->height += sin(delta_z) * 3;
		tree->center_x = center_x + delta_x;
		tree->center_z = center_z + delta_z;
		trees.push_back(tree);
	};
	return trees;
}

void TerrainTile::delete_trees(){
	std::vector<TerrainTree*>::iterator iter;
	for (iter=trees.begin();iter != trees.end();iter++){
		delete *iter;
	};
	trees.clear();
}

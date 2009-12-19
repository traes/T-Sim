
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "TerrainTileRepresentation.h"

TerrainTileRepresentation::TerrainTileRepresentation(){
	wireframe = false;
	house_representation = TerrainHouseRepresentation();
	tree_representation = TerrainTreeRepresentation();
}

void TerrainTileRepresentation::show(TerrainTile* tile,float step){
	show_terrain(tile,step);
	show_houses(tile);
	show_trees(tile);
}	

void TerrainTileRepresentation::show_houses(TerrainTile* tile){
	std::vector<TerrainHouse*> houses = tile->create_houses();
	std::vector<TerrainHouse*>::iterator iter;
	for(iter = houses.begin(); iter != houses.end(); iter++){
		TerrainHouse* house = *iter;
		house_representation.show(house);
	};
	tile->delete_houses();
}

void TerrainTileRepresentation::show_trees(TerrainTile* tile){
	std::vector<TerrainTree*> trees = tile->create_trees();
	std::vector<TerrainTree*>::iterator iter;
	for(iter = trees.begin(); iter != trees.end(); iter++){
		TerrainTree* tree = *iter;
		tree_representation.show(tree);
	};
	tile->delete_trees();
}

void TerrainTileRepresentation::show_terrain(TerrainTile* tile,float step){
	float width = tile->dimension;
	float length = tile->dimension;
	float x_min = tile->center_x - width/2;
	float x_max = tile->center_x + width/2;
	float z_min = tile->center_z - length/2;
	float z_max = tile->center_z + length/2;
	float x;
	float z;
	for(x = x_min; x < x_max; x += step ){
		for(z = z_min; z < z_max; z += step){
			//Color color1 = tile->base_color;
			Color color2 = tile->color(z,x);
			Color color1 = color2;
			if (wireframe){
				glLineWidth(1);
				glBegin(GL_LINES);
			} else {
				glBegin(GL_TRIANGLES);
			};
			glColor3f(color1.red,color1.green,color1.blue);

			// west 
			glVertex3f(x,tile->height(x,z),z);
			glVertex3f(x,tile->height(x,z+step),z+step);
			glColor3f(color2.red,color2.green,color2.blue);
			glVertex3f(x+step/2,tile->height(x+step/2,z+step/2),z+step/2);
			glColor3f(color1.red,color1.green,color1.blue);

			// north 
			glVertex3f(x,tile->height(x,z+step),z+step);
			glVertex3f(x+step,tile->height(x+step,z+step),z+step);
			glColor3f(color2.red,color2.green,color2.blue);
			glVertex3f(x+step/2,tile->height(x+step/2,z+step/2),z+step/2);
			glColor3f(color1.red,color1.green,color1.blue);

			// east
			glVertex3f(x+step,tile->height(x+step,z+step),z+step);
			glVertex3f(x+step,tile->height(x+step,z),z);
			glColor3f(color2.red,color2.green,color2.blue);
			glVertex3f(x+step/2,tile->height(x+step/2,z+step/2),z+step/2);
			glColor3f(color1.red,color1.green,color1.blue);

			// south
			glVertex3f(x,tile->height(x,z),z);
			glColor3f(color2.red,color2.green,color2.blue);
			glVertex3f(x+step/2,tile->height(x+step/2,z+step/2),z+step/2);
			glColor3f(color1.red,color1.green,color1.blue);
			glVertex3f(x+step,tile->height(x+step,z),z);
			glEnd();

		}
	}
}

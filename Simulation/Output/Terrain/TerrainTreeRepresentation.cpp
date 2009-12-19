#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "TerrainTreeRepresentation.h"

TerrainTreeRepresentation::TerrainTreeRepresentation(){
}

void TerrainTreeRepresentation::show(TerrainTree* tree){
	show_trunk(tree);
	show_leafs(tree);
}

void TerrainTreeRepresentation::show_trunk(TerrainTree* tree){
	glColor3f(0.2f,0.2f,0);
	float center_x = tree->center_x;
	float center_z = tree->center_z;
	float height = tree->height;
	float width = 1.0;
	glBegin(GL_TRIANGLES);
	// bottom
	glVertex3f(center_x,0,center_z - width/2);
	glVertex3f(center_x + width/2,0,center_z + width/2);
	glVertex3f(center_x - width/2,0,center_z + width/2);
	// top 
	glVertex3f(center_x,height,center_z - width/2);
	glVertex3f(center_x + width/2,height,center_z - width/2);
	glVertex3f(center_z - width/2,height,center_z + width/2);
	glEnd();
	glBegin(GL_QUADS);
	// left
	glVertex3f(center_x,0,center_z - width/2);
	glVertex3f(center_x,height,center_z - width/2);
	glVertex3f(center_x - width/2,height,center_z + width/2);
	glVertex3f(center_x - width/2,0,center_z + width/2);
	// right
	glVertex3f(center_x,0,center_z - width/2);
	glVertex3f(center_x,height,center_z - width/2);
	glVertex3f(center_x + width/2,height,center_z - width/2);
	glVertex3f(center_x + width/2,0,center_z - width/2);
	// back
	glVertex3f(center_x - width/2,0,center_z - width/2);
	glVertex3f(center_x - width/2,height,center_z - width/2);
	glVertex3f(center_x + width/2,height,center_z + width/2);
	glVertex3f(center_x + width/2,0,center_z + width/2);
	glEnd();
}

void TerrainTreeRepresentation::show_leafs(TerrainTree* tree){
	float center_x = tree->center_x;
	float center_z = tree->center_z;
	float base_height = tree->height;
	float top_height = base_height * 2.0f;
	float width = 3.0f;
	float length = 3.0f;
	glColor3f(tree->color.red,tree->color.green,tree->color.blue);
	glBegin(GL_QUADS);
	// front
	glVertex3f(center_x - width/2,base_height,center_z - length/2);
	glVertex3f(center_x - width/2,base_height,center_z + length/2);
	glVertex3f(center_x - width/2,top_height,center_z + length/2);
	glVertex3f(center_x - width/2,top_height,center_z - length/2);
	// back
	glVertex3f(center_x + width/2,base_height,center_z - length/2);
	glVertex3f(center_x + width/2,base_height,center_z + length/2);
	glVertex3f(center_x + width/2,top_height,center_z + length/2);
	glVertex3f(center_x + width/2,top_height,center_z - length/2);
	// left
	glVertex3f(center_x - width/2,base_height,center_z - length/2);
	glVertex3f(center_x - width/2,top_height,center_z - length/2);
	glVertex3f(center_x + width/2,top_height,center_z - length/2);
	glVertex3f(center_x + width/2,base_height,center_z - length/2);
	// right
	glVertex3f(center_x - width/2,base_height,center_z + length/2);
	glVertex3f(center_x - width/2,top_height,center_z + length/2);
	glVertex3f(center_x + width/2,top_height,center_z + length/2);
	glVertex3f(center_x + width/2,base_height,center_z + length/2);
	// bottom
	glVertex3f(center_x - width/2,base_height,center_z - length/2);
	glVertex3f(center_x - width/2,base_height,center_z + length/2);
	glVertex3f(center_x + width/2,base_height,center_z + length/2);
	glVertex3f(center_x + width/2,base_height,center_z - length/2);
	glEnd();
}

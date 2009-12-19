#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "TerrainHouseRepresentation.h"

TerrainHouseRepresentation::TerrainHouseRepresentation(){
}

void TerrainHouseRepresentation::show(TerrainHouse* house){
	float width = house->width;
	float length = house->length;
	float wall_height = house->wall_height;
	float roof_height = house->roof_height;
	float center_x = house->center_x;
	float center_z = house->center_z;
	float base_height = 0.0f;
	//--- walls ---
	glColor3f(house->wall_color.red,house->wall_color.green,house->wall_color.blue);
	glBegin(GL_QUADS);
	// front
	glVertex3f(center_x - width/2,base_height,center_z - length/2);
	glVertex3f(center_x - width/2,base_height,center_z + length/2);
	glVertex3f(center_x - width/2,wall_height,center_z + length/2);
	glVertex3f(center_x - width/2,wall_height,center_z - length/2);
	// back
	glVertex3f(center_x + width/2,base_height,center_z - length/2);
	glVertex3f(center_x + width/2,base_height,center_z + length/2);
	glVertex3f(center_x + width/2,wall_height,center_z + length/2);
	glVertex3f(center_x + width/2,wall_height,center_z - length/2);
	// left
	glVertex3f(center_x - width/2,base_height,center_z - length/2);
	glVertex3f(center_x - width/2,wall_height,center_z - length/2);
	glVertex3f(center_x + width/2,wall_height,center_z - length/2);
	glVertex3f(center_x + width/2,base_height,center_z - length/2);
	// right
	glVertex3f(center_x - width/2,base_height,center_z + length/2);
	glVertex3f(center_x - width/2,wall_height,center_z + length/2);
	glVertex3f(center_x + width/2,wall_height,center_z + length/2);
	glVertex3f(center_x + width/2,base_height,center_z + length/2);

	// --- roof ---
	glColor3f(house->roof_color.red,house->roof_color.green,house->roof_color.blue);
	// front
	glVertex3f(center_x - width/2,wall_height,center_z - length/2);
	glVertex3f(center_x,wall_height + roof_height,center_z - length/2);
	glVertex3f(center_x,wall_height + roof_height,center_z + length/2);
	glVertex3f(center_x - width/2,wall_height,center_z + length/2);
	// back
	glVertex3f(center_x + width/2,wall_height,center_z - length/2);
	glVertex3f(center_x,wall_height + roof_height,center_z - length/2);
	glVertex3f(center_x,wall_height + roof_height,center_z + length/2);
	glVertex3f(center_x + width/2,wall_height,center_z + length/2);

	glEnd();
	glBegin(GL_TRIANGLES);
	// left roof part
	glVertex3f(center_x - width/2,wall_height,center_z - length/2);
	glVertex3f(center_x,wall_height + roof_height,center_z - length/2);
	glVertex3f(center_x + width/2,wall_height,center_z - length/2);

	// right roof part
	glVertex3f(center_x - width/2,wall_height,center_z + length/2);
	glVertex3f(center_x,wall_height + roof_height,center_z + length/2);
	glVertex3f(center_x + width/2,wall_height,center_z + length/2);
	glEnd();
}


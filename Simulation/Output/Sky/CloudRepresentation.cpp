#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "CloudRepresentation.h"

CloudRepresentation::CloudRepresentation(){
}

void CloudRepresentation::show(Cloud* cloud){
	glPushMatrix();
	glTranslatef(cloud->position.x,cloud->position.y,cloud->position.z);
	glBegin(GL_TRIANGLES);
	glColor3f(1,1,1);
	glVertex3f(-cloud->width,0,-cloud->length);
	glVertex3f(cloud->width,0,-cloud->length);
	glVertex3f(cloud->width,0,cloud->length);
	glEnd();
	glPopMatrix();
}

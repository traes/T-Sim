#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "CompassRepresentation.h"

CompassRepresentation::CompassRepresentation(){
	width = 0.1f;
	height = 0.1f;
}

void CompassRepresentation::show(Compass* compass){
	glPushMatrix();
	show_background(compass);
	glTranslatef(0,0,0.008f);
	glRotatef(compass->heading,0,0,1);
	show_directions();
	glPopMatrix();
}

void CompassRepresentation::show_directions(){
	// north
	glColor3f(1,1,1);
	glBegin(GL_QUADS);
	glVertex3f(-0.001,0,0);
	glVertex3f(-0.001,height/2.0,0);
	glVertex3f(0.001,height/2.0,0);
	glVertex3f(0.001,0,0);
	glEnd();
	// south
	glColor3f(1,0,0);
	glBegin(GL_QUADS);
	glVertex3f(-0.001,-height/2.0,0);
	glVertex3f(-0.001,0,0);
	glVertex3f(0.001,0,0);
	glVertex3f(0.001,-height/2.0,0);
	glEnd();

}

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "InstrumentRepresentation.h"

InstrumentRepresentation::InstrumentRepresentation(){
	width = 0.1f;
	height = 0.1f;
}

void InstrumentRepresentation::show(Instrument* instrument){
	show_background(instrument);
}

void InstrumentRepresentation::show_background(Instrument* instrument){
	glPushMatrix();
	float x = width/2.0f;
	float y = height/2.0f;
	// circle
	glColor3f(1,1,1);
	glTranslatef(0,0,0.00015);
	float begin = height/2;
	float end = 1.05 * begin;
	for(int i = 0; i < 360; i++){
		glRotatef(1,0,0,1);
		glBegin(GL_QUADS);
		glVertex3f(-0.001,begin,0);
		glVertex3f(-0.001,end,0);
		glVertex3f(0.001,end,0);
		glVertex3f(0.001,begin,0);
		glEnd();
	};
	glPopMatrix();

}


#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "RotorRepresentation.h"

RotorRepresentation::RotorRepresentation(){
	min_rpm_for_disk = 250.0f;
}

void RotorRepresentation::show(Rotor* rotor){
	glPushMatrix();
	glRotatef(rotor->orientation.z,0,0,1);
	glRotatef(rotor->orientation.y,0,1,0);
	glRotatef(rotor->orientation.x,1,0,0);
	if (rotor->rpm > min_rpm_for_disk){
		show_rotor_as_disk(rotor);
	} else {
		show_rotor_as_blades(rotor);
	};	
	glPopMatrix();
}

void RotorRepresentation::show_rotor_as_blades(Rotor* rotor){
	glColor3f(0,0,0);
	float angle_between_blades = 360.0f/((float) rotor->b);
	for(int blade = 0; blade < rotor->b; blade++){
		glRotatef(angle_between_blades,0,1,0);	
		show_single_blade(rotor);
	};
}

void RotorRepresentation::show_rotor_as_disk(Rotor* rotor){
	glColor3f(0.8,0.8,0.8);
	for(int i = 0; i < 360; i++){
		glRotatef(1.0f,0,1,0);	
		show_single_blade(rotor);
	};
}

void RotorRepresentation::show_single_blade(Rotor* rotor){
	glPushMatrix();
	float c = rotor->c;
	float r_h = rotor->r_h;
	float r_t = rotor->r_t;
	glRotatef(rotor->theta*30.0f,0,0,1);
	glBegin(GL_QUADS);
		glVertex3f(-c/2,0,r_h);
		glVertex3f(-c/2,0,r_t);
		glVertex3f(c/2,0,r_t);
		glVertex3f(c/2,0,r_h);
	glEnd();
	glPopMatrix();
}

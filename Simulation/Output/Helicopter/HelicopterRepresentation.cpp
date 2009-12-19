#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "HelicopterRepresentation.h"

HelicopterRepresentation::HelicopterRepresentation(){
	rotor_representation = RotorRepresentation();
}


void HelicopterRepresentation::show(Helicopter* helicopter){
	// === Show Main Rotor === 
	glPushMatrix();
	glTranslatef(0,2,0); // rotor height above fuselage center
	rotor_representation.show(&(helicopter->main_rotor));
	glPopMatrix();
	
	// === Show Tail Rotor === 
	glPushMatrix();
	glTranslatef(0.25,1.5,7); // tail rotor distance
	rotor_representation.show(&(helicopter->tail_rotor));
	glPopMatrix();

	/* === Show Fuselage === */
	// --- Nose --- 
	glBegin(GL_TRIANGLES);

	// left front window
	glColor3f(0,1,1); // window	
	glVertex3f(-1,0,-2);
	glVertex3f(-1,1.5,-2);
	glVertex3f(-0.5,0,-4);

	// right front window
	glColor3f(0,1,1); // window	
	glVertex3f(1,0,-2);
	glVertex3f(1,1.5,-2);
	glVertex3f(0.5,0,-4);

	glEnd();
	
	glBegin(GL_QUADS);
	// front
	glColor3f(0,0,0);	
	glVertex3f(-0.5,0,-4);
	glVertex3f(0.5,0,-4);
	glVertex3f(0.5,-0.5,-4);
	glVertex3f(-0.5,-0.5,-4);

	// left
	glColor3f(1,0,0);	
	glVertex3f(-1,0,-2);
	glVertex3f(-0.5,0,-4);
	glVertex3f(-0.5,-0.5,-4);
	glVertex3f(-1,-1.5,-2);

	// right
	glColor3f(1,0,0);	
	glVertex3f(1,0,-2);
	glVertex3f(0.5,0,-4);
	glVertex3f(0.5,-0.5,-4);
	glVertex3f(1,-1.5,-2);

	// up
	glColor3f(0,1,1); // window	
	glVertex3f(-1,1.5,-2);
	glVertex3f(1,1.5,-2);
	glVertex3f(0.5,0,-4);
	glVertex3f(-0.5,0,-4);

	// down
	glColor3f(1,1,1);
	glVertex3f(-0.5,-0.5,-4);
	glVertex3f(0.5,-0.5,-4);
	glVertex3f(1,-1.5,-2);
	glVertex3f(-1,-1.5,-2);

	// --- Center ---

	// up
	glColor3f(1,1,1);	
	glVertex3f(-1,1.5,-2);
	glVertex3f(-1,1.5,1);
	glVertex3f(1,1.5,1);
	glVertex3f(1,1.5,-2);

	// down
	glVertex3f(-1,-1.5,-2);
	glVertex3f(-1,-1.5,1);
	glVertex3f(1,-1.5,1);
	glVertex3f(1,-1.5,-2);

	// left
	glColor3f(1,0,0);	
	glVertex3f(-1,1.5,-2);
	glVertex3f(-1,-1.5,-2);
	glVertex3f(-1,-1.5,1);
	glVertex3f(-1,1.5,1);

	// right
	glVertex3f(1,1.5,-2);
	glVertex3f(1,-1.5,-2);
	glVertex3f(1,-1.5,1);
	glVertex3f(1,1.5,1);

	// --- Tail ---

	// tailfin
	glColor3f(1,1,1);	
	glVertex3f(0,1.5,5);
	glVertex3f(0,3,7);
	glVertex3f(0,3,8);
	glVertex3f(0,1.5,7);

	glEnd();
	glBegin(GL_TRIANGLES);

	// up
	glColor3f(1,1,1);	
	glVertex3f(-1,1.5,1);
	glVertex3f(0,1.5,7);
	glVertex3f(1,1.5,1);
	
	// down
	glColor3f(1,1,1);	
	glVertex3f(-1,-1.5,1);
	glVertex3f(0,1.5,7);
	glVertex3f(1,-1.5,1);

	// right
	glColor3f(1,0,0);	
	glVertex3f(1,-1.5,1);
	glVertex3f(1,1.5,1);
	glVertex3f(0,1.5,7);

	// left
	glColor3f(1,0,0);	
	glVertex3f(-1,-1.5,1);
	glVertex3f(-1,1.5,1);
	glVertex3f(0,1.5,7);

	glEnd();


	// landing skid
	glColor3f(0,0,0);
	glLineWidth(4);
	glBegin (GL_LINES);
		// --- Left ---
		// front paw
		glVertex3f(-1,-1.5,-2);
		glVertex3f(-1.5,-2,-2);
		
		// back paw
		glVertex3f(-1,-1.5,1);
		glVertex3f(-1.5,-2,1);

		// skid
		glVertex3f(-1.5,-2,-3);
		glVertex3f(-1.5,-2,2);
		
		// --- Right ---
		// front paw
		glVertex3f(1,-1.5,-2);
		glVertex3f(1.5,-2,-2);
		
		// back paw
		glVertex3f(1,-1.5,1);
		glVertex3f(1.5,-2,1);

		// skid
		glVertex3f(1.5,-2,-3);
		glVertex3f(1.5,-2,2);
	glEnd();
}

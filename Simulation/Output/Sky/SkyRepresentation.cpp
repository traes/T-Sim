#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "SkyRepresentation.h"
#include <math.h>

SkyRepresentation::SkyRepresentation(){
	cloud_representation = CloudRepresentation();
}

void SkyRepresentation::show(Sky* sky,Vector3D* position){
	show_air(sky,position);
	show_clouds(sky,position);
}	

void SkyRepresentation::show_clouds(Sky* sky,Vector3D* position){
	std::vector<Cloud>::iterator iter;
	for (iter = sky->clouds.begin(); iter != sky->clouds.end(); iter++){
		Cloud* cloud = &(*iter);
		cloud_representation.show(cloud);
	};
}

void SkyRepresentation::show_air(Sky* sky,Vector3D* position){
	float horizon = 2000.0f;
	float ceiling = position->y + 5000.0f;
	glBegin(GL_QUADS);
	// front
	glColor3f(0.8,0.8,1);
	glVertex3f(-horizon,0,-horizon);
	glVertex3f(horizon,0,-horizon);
	glColor3f(0,0,1);
	glVertex3f(horizon,ceiling,-horizon);
	glVertex3f(-horizon,ceiling,-horizon);
	// right
	glColor3f(0.8,0.8,1);
	glVertex3f(horizon,0,-horizon);
	glVertex3f(horizon,0,horizon);
	glColor3f(0,0,1);
	glVertex3f(horizon,ceiling,horizon);
	glVertex3f(horizon,ceiling,-horizon);
	// back
	glColor3f(0.8,0.8,1);
	glVertex3f(-horizon,0,horizon);
	glVertex3f(horizon,0,horizon);
	glColor3f(0,0,1);
	glVertex3f(horizon,ceiling,horizon);
	glVertex3f(-horizon,ceiling,horizon);
	// left 
	glColor3f(0.8,0.8,1);
	glVertex3f(-horizon,0,-horizon);
	glVertex3f(-horizon,0,horizon);
	glColor3f(0,0,1);
	glVertex3f(-horizon,ceiling,horizon);
	glVertex3f(-horizon,ceiling,-horizon);
	// top
	glColor3f(0,0,1);
	glVertex3f(-horizon,ceiling,horizon);
	glVertex3f(horizon,ceiling,horizon);
	glVertex3f(horizon,ceiling,-horizon);
	glVertex3f(-horizon,ceiling,-horizon);
	glEnd();
}

#include <math.h>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "ArtificialHorizonRepresentation.h"

ArtificialHorizonRepresentation::ArtificialHorizonRepresentation(){
	width = 0.1f;
	height = 0.1f;
}

void ArtificialHorizonRepresentation::show(ArtificialHorizon* artificial_horizon){
	glPushMatrix();
	show_background(artificial_horizon);
	glTranslatef(0,0,0.0003);
	glRotatef(artificial_horizon->roll,0,0,1);
	show_horizon(artificial_horizon);
	glPopMatrix();
	show_cover(artificial_horizon);
}

void ArtificialHorizonRepresentation::show_horizon(ArtificialHorizon* artificial_horizon){
	glPushMatrix();
	glTranslatef(0,0,0.003f);
	float roll = artificial_horizon->roll;
	float pitch = artificial_horizon->pitch;
	float border_left = 0;
	float border_right = 0;
	float delta_pitch = pitch_border_delta(pitch);
	border_left -= delta_pitch;
	border_right -= delta_pitch;
	if (border_left < -height/3)
		border_left = -height/3;
	if (border_left > height/3)
		border_left = height/3;
	if (border_right < -height/3)
		border_right = -height/3;
	if (border_right > height/3)
		border_right = height/3;
	// blue sky
	glColor3f(0.1,0.1,0.9);
	glBegin(GL_QUADS);
	glVertex3f(-width/3,height/3,0);
	glVertex3f(width/3,height/3,0);
	glVertex3f(width/3,border_right,0);
	glVertex3f(-width/3,border_left,0);
	glEnd();
	// orange ground
	glColor3f(0.9,0.4,0);
	glBegin(GL_QUADS);
	glVertex3f(-width/3,border_left,0);
	glVertex3f(width/3,border_right,0);
	glVertex3f(width/3,-height/3,0);
	glVertex3f(-width/3,-height/3,0);
	glEnd();
	glPopMatrix();

}

void ArtificialHorizonRepresentation::show_cover(ArtificialHorizon* artificial_horizon){
	glPushMatrix();
	glTranslatef(0,0,0.004);
	float cover_begin = height/3;
	float cover_end = height/2;
	glRotatef(-90,0,0,1);
	// blue sky
	glColor3f(0.2,0.2,1);
	for(int i=0; i < 180; i++){
		glRotatef(1,0,0,1);
		glBegin(GL_QUADS);
		glVertex3f(-0.001,cover_begin,0);
		glVertex3f(-0.001,cover_end,0);
		glVertex3f(0.001,cover_end,0);
		glVertex3f(0.001,cover_begin,0);
		glEnd();
	}
	// orange ground
	glColor3f(1,0.5,0);
	for(int i=0; i < 180; i++){
		glRotatef(1,0,0,1);
		glBegin(GL_QUADS);
		glVertex3f(-0.001,cover_begin,0);
		glVertex3f(-0.001,cover_end,0);
		glVertex3f(0.001,cover_end,0);
		glVertex3f(0.001,cover_begin,0);
		glEnd();
	}
	glPopMatrix();
}

float ArtificialHorizonRepresentation::pitch_border_delta(float pitch){
	float max_display_pitch = 15.0f; // degrees
	float display_pitch_proportion = pitch / max_display_pitch;
	return (display_pitch_proportion * height/2);
}


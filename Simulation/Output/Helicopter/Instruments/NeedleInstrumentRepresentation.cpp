#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>

#include "NeedleInstrumentRepresentation.h"

NeedleInstrumentRepresentation::NeedleInstrumentRepresentation(){
	needle_representation = NeedleRepresentation();
}

void NeedleInstrumentRepresentation::show(NeedleInstrument* instrument){
	glPushMatrix();
	glRotatef(-(instrument->neutral_orientation),0,0,1);
	show_background(instrument); // height 0.0001 (InstrumentRepresentation)
	show_color_indications(instrument); // height 0.0002
	show_values(instrument); // height 0.0003
	show_marks(instrument); // height 0.0004
	show_needle(instrument); // height 0.0005
	glPopMatrix();
}

void NeedleInstrumentRepresentation::show_values(NeedleInstrument* instrument){
	glPushMatrix();
	glTranslatef(0,0,0.0003f);
	glColor3f(1,1,1);
	float distance_from_center = 0.6 * height/2.0; 
	float value = 0;
	float angle = 0;
	for(int mark = 0; mark < instrument->number_of_marks; mark++){
		glPushMatrix();
		glRotatef(-angle,0,0,1);
		glTranslatef(0,distance_from_center,0);
		glRotatef(angle,0,0,1);
		glRotatef((instrument->neutral_orientation),0,0,1);
		number_representation.show((int)value,0.006f);
		glPopMatrix();
		value += instrument->mark_delta_value;
		angle += instrument->mark_delta_angle;
	};
	glPopMatrix();
}

void NeedleInstrumentRepresentation::show_marks(NeedleInstrument* instrument){
	glPushMatrix();
	glTranslatef(0,0,0.0004f);
	glColor3f(1,1,1);
	float value = 0;
	float angle = 0;
	float half_mark_width = 0.0005f;
	float mark_begin_length = 0.8 * height/2.0; 
	float mark_end_length = height/2.0; 
	for(int mark = 0; mark < instrument->number_of_marks; mark++){
		glPushMatrix();
		glRotatef(-angle,0,0,1);
		glBegin(GL_QUADS);
		glVertex3f(-half_mark_width,mark_begin_length,0);
		glVertex3f(-half_mark_width,mark_end_length,0);
		glVertex3f(half_mark_width,mark_end_length,0);
		glVertex3f(half_mark_width,mark_begin_length,0);
		glEnd();
		glPopMatrix();
		value += instrument->mark_delta_value;
		angle += instrument->mark_delta_angle;
	};
	glPopMatrix();
}

void NeedleInstrumentRepresentation::show_needle(NeedleInstrument* instrument){
	glTranslatef(0,0,0.0005f);
	std::vector<Needle>::iterator needle;
	for(needle = instrument->needles.begin(); needle != instrument->needles.end(); needle++){
		glPushMatrix();
		glTranslatef(needle->origin.x,0,0);
		glTranslatef(0,needle->origin.y,0);
		glTranslatef(0,0,needle->origin.z);
		float angle = needle->get_angle(instrument->value);
		glRotatef(-angle,0,0,1);
		needle_representation.show(&(*needle));
		glPopMatrix();
	};
}

void NeedleInstrumentRepresentation::show_color_indications(NeedleInstrument* instrument){
	glTranslatef(0,0,0.0002f);
	std::vector<ColorIndication>::iterator i;
	float begin_length = 0.9 * height/2.0; 
	float end_length = height/2.0; 
	for(i = instrument->color_indications.begin(); i != instrument->color_indications.end(); i++){
		glPushMatrix();
		glColor3f(i->red,i->green,i->blue);
		float begin_angle = instrument->get_angle(i->begin_value);
		float end_angle = instrument->get_angle(i->end_value);
		glRotatef(-begin_angle,0,0,1);
		float delta_angle = 1.0f;
		for(float angle = begin_angle; angle < end_angle; angle += delta_angle){
			glRotatef(-delta_angle,0,0,1);
			glBegin(GL_QUADS);
			glVertex3f(-0.001,begin_length,0);
			glVertex3f(-0.001,end_length,0);
			glVertex3f(0.001,end_length,0);
			glVertex3f(0.001,begin_length,0);
			glEnd();
		}
		glPopMatrix();
	};
}

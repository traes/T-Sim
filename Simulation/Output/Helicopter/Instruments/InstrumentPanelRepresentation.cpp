#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "InstrumentPanelRepresentation.h"
#include <iostream>

InstrumentPanelRepresentation::InstrumentPanelRepresentation(){
	artificial_horizon_representation = ArtificialHorizonRepresentation();
	compass_representation = CompassRepresentation();
	needle_instrument_representation = NeedleInstrumentRepresentation();
	width = 0.5;
	height = 0.3;
	viewing_distance = 0.45f;
}


void InstrumentPanelRepresentation::show(InstrumentPanel* instrument_panel){
	glPushMatrix();
	glTranslatef(0,0,-viewing_distance);
	show_panel_background(instrument_panel);
	show_instruments(instrument_panel);
	show_lights(instrument_panel);
	glPopMatrix();

}

void InstrumentPanelRepresentation::show_panel_background(InstrumentPanel* instrument_panel){
	// TODO: get width and height from instrument panel
	glColor3f(0.0f,0.0f,0.0f);
	glBegin(GL_QUADS);
	glVertex3f(-width/2.5,-height/2.0,0);
	glVertex3f(-width/2.0,height/2.0,0);
	glVertex3f(width/2.0,height/2.0,0);
	glVertex3f(width/2.5,-height/2.0,0);
	glEnd();

}

void InstrumentPanelRepresentation::show_instruments(InstrumentPanel* instrument_panel){
	glPushMatrix(); // begin instrument panel
	float horizontal_distance = 0.11f;
	float vertical_distance = 0.11f;

	// upper row
	glPushMatrix(); // begin upper row
	glTranslatef(-1.5*horizontal_distance,0.5*vertical_distance,0);
	needle_instrument_representation.show(&(instrument_panel->climb_indicator));
	glTranslatef(horizontal_distance,0,0);
	artificial_horizon_representation.show(&(instrument_panel->artificial_horizon));
	glTranslatef(horizontal_distance,0,0);
	needle_instrument_representation.show(&(instrument_panel->airspeed_indicator));
	glTranslatef(horizontal_distance,0,0);
	needle_instrument_representation.show(&(instrument_panel->rpm_indicator));
	glPopMatrix(); // end upper row

	// lower row
	glPushMatrix(); // begin lower row
	glTranslatef(-horizontal_distance,-0.5*vertical_distance,0);
	needle_instrument_representation.show(&(instrument_panel->altitude_indicator));
	glTranslatef(horizontal_distance,0,0);
	compass_representation.show(&(instrument_panel->compass));
	glTranslatef(horizontal_distance,0,0);
	needle_instrument_representation.show(&(instrument_panel->air_pressure_indicator));
	glPopMatrix(); // end lower row

	glPopMatrix(); // end instrument panel
}

void InstrumentPanelRepresentation::show_lights(InstrumentPanel* instrument_panel){
	glPushMatrix();
	glColor3f(0.0f,0.0f,0.0f);
	glBegin(GL_QUADS);
	glVertex3f(-width/3,height/2.0,0);
	glVertex3f(-width/3.5,height/2.0+0.05f,0);
	glVertex3f(width/3.5,height/2.0+0.05f,0);
	glVertex3f(width/3,height/2.0,0);
	glEnd();
	int number_of_lights = 7;
	float lights_distance = (width/1.8)/(number_of_lights - 1);
	glTranslatef(-width/3.5,height/2.0+0.025f,0.001f);
	for(int light=0; light < number_of_lights; light++){
		show_warning_light();
		glTranslatef(lights_distance,0,0);
	}
	glPopMatrix();
}


void InstrumentPanelRepresentation::show_warning_light(){
	glPushMatrix();
	float half_width = 0.006f;
	glColor3f(0.5,0,0);
	for(int i=0; i < 90; i++){
		glRotatef(1,0,0,1);
		glBegin(GL_QUADS);
		glVertex3f(-half_width,-half_width,0);
		glVertex3f(-half_width,half_width,0);
		glVertex3f(half_width,half_width,0);
		glVertex3f(half_width,-half_width,0);
		glEnd();
	}
	glPopMatrix();
}

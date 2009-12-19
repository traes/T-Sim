#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "CockpitView.h"

CockpitView::CockpitView(){
	instrument_panel_representation = InstrumentPanelRepresentation();
	terrain_representation = TerrainRepresentation();
	rotor_representation = RotorRepresentation();
	sky_representation = SkyRepresentation();
}

void CockpitView::show(World* world,Camera* camera){
	float position_x = world->helicopter.position.x;
	float position_y = world->helicopter.position.y;
	float position_z = world->helicopter.position.z;

	float orientation_x = world->helicopter.orientation.x;
	float orientation_y = world->helicopter.orientation.y;
	float orientation_z = world->helicopter.orientation.z;

	glPushMatrix();
	
	// camera
	glRotatef(-camera->orientation.x,1,0,0);
	glRotatef(-camera->orientation.y,0,1,0);
	glRotatef(-camera->orientation.z,0,0,1);
	glTranslatef(0,-0.2f,0);

	// --- Rotor ---
	glPushMatrix();
	glTranslatef(0,1.1f,0);
	rotor_representation.show(&(world->helicopter.main_rotor));
	glPopMatrix();

	// --- InstrumentPanel ---
	glPushMatrix();
	glTranslatef(0,0,-0.55f);
	instrument_panel_representation.show(&(world->helicopter.instrument_panel));
	glPopMatrix();

	// --- Floor ---
	float half_floor_width = 1.0f;
	float half_floor_length = 3.0f;
	glPushMatrix();
	glTranslatef(0,-1.0f,0);
	glBegin(GL_QUADS);
		glColor3f(0.2,0.2,0.2);
		// bottom
		glVertex3f(-half_floor_width/1.5,0,-half_floor_length);
		glVertex3f(-half_floor_width,0,half_floor_length);
		glVertex3f(half_floor_width,0,half_floor_length);
		glVertex3f(half_floor_width/1.5,0,-half_floor_length);
		glColor3f(0.3,0.3,0.3);
		// left part
		glVertex3f(-half_floor_width/1.5,0,-half_floor_length);
		glVertex3f(-half_floor_width/1.5,0.3f,-half_floor_length);
		glVertex3f(-half_floor_width,0.3f,half_floor_length);
		glVertex3f(-half_floor_width,0.0f,half_floor_length);
		// right part
		glVertex3f(half_floor_width/1.5,0,-half_floor_length);
		glVertex3f(half_floor_width/1.5,0.3f,-half_floor_length);
		glVertex3f(half_floor_width,0.3f,half_floor_length);
		glVertex3f(half_floor_width,0.0f,half_floor_length);
		// front part
		glVertex3f(half_floor_width/1.5,0,-half_floor_length);
		glVertex3f(half_floor_width/1.5,0.3f,-half_floor_length);
		glVertex3f(-half_floor_width/1.5,0.3f,-half_floor_length);
		glVertex3f(-half_floor_width/1.5,0,-half_floor_length);
	glEnd();
	glPopMatrix();

	// --- Roof ---
	float half_roof_width = 1.0f;
	float roof_length = 2.0f;
	glColor3f(0.7,0.7,0.7);
	glPushMatrix();
	glTranslatef(0,1.0f,0);
	glBegin(GL_QUADS);
		glVertex3f(-half_floor_width,0,roof_length);
		glVertex3f(half_floor_width,0,roof_length);
		glVertex3f(half_floor_width/3,0,-roof_length);
		glVertex3f(-half_floor_width/3,0,-roof_length);
	glEnd();
	glPopMatrix();

	glColor3f(0.9,0.9,0.9);
	// --- Vertical Front Bar ---
	float half_bar_width = 0.05f;
	glBegin(GL_QUADS);
		glVertex3f(-half_bar_width,1.1f,-roof_length + 0.1f);
		glVertex3f(half_bar_width,1.1f,-roof_length + 0.1f);
		glVertex3f(half_bar_width,-0.5f,-half_floor_length);
		glVertex3f(-half_bar_width,-0.5f,-half_floor_length);
	glEnd();

	// --- Left Bar ---
	glBegin(GL_QUADS);
		glVertex3f(-half_floor_width,-half_bar_width,-half_floor_length);
		glVertex3f(-half_floor_width,half_bar_width,-half_floor_length);
		glVertex3f(-half_floor_width,half_bar_width,half_floor_length);
		glVertex3f(-half_floor_width,-half_bar_width,half_floor_length);

	glEnd();

	// --- Right Bar ---
	glBegin(GL_QUADS);
		glVertex3f(half_floor_width,-half_bar_width,-half_floor_length);
		glVertex3f(half_floor_width,half_bar_width,-half_floor_length);
		glVertex3f(half_floor_width,half_bar_width,half_floor_length);
		glVertex3f(half_floor_width,-half_bar_width,half_floor_length);
	glEnd();

	// --- Horizontal Front Bar ---
	glBegin(GL_QUADS);
		glVertex3f(-half_floor_width,-half_bar_width,-half_floor_length);
		glVertex3f(-half_floor_width,half_bar_width,-half_floor_length);
		glVertex3f(half_floor_width,-half_bar_width,-half_floor_length);
		glVertex3f(half_floor_width,half_bar_width,-half_floor_length);
	glEnd();	

	// --- Backside ---
	float half_backside_width = 1.0f;
	float half_backside_height = 1.0f;
	glColor3f(0.2,0.2,0.2);
	glPushMatrix();
	glTranslatef(0,0,2.0f);
	glBegin(GL_QUADS);
		glVertex3f(-half_backside_width,-half_backside_height,0);
		glVertex3f(-half_backside_width,half_backside_height,0);
		glVertex3f(half_backside_width,half_backside_height,0);
		glVertex3f(half_backside_width,-half_backside_height,0);
	glEnd();
	glPopMatrix();

	// --- Cyclic ---
	glColor3f(0.8,0.8,0.8);
	glPushMatrix();
	float x_angle = world->helicopter.cyclic_x * 30;
	float z_angle = world->helicopter.cyclic_z * 30;
	glTranslatef(0,-0.5,-0.52f);
	glRotatef(x_angle,1,0,0);
	glRotatef(z_angle,0,0,1);
	float cyclic_height = 0.5f;
	float half_cyclic_width = 0.005f;
	// stick
	glBegin(GL_QUADS);
		// front
		glColor3f(0.4,0.4,0.4);
		glVertex3f(-half_cyclic_width,0,half_cyclic_width);
		glVertex3f(-half_cyclic_width,cyclic_height,half_cyclic_width);
		glVertex3f(half_cyclic_width,cyclic_height,half_cyclic_width);
		glVertex3f(half_cyclic_width,0,half_cyclic_width);
		// back
		glVertex3f(-half_cyclic_width,0,-half_cyclic_width);
		glVertex3f(-half_cyclic_width,cyclic_height,-half_cyclic_width);
		glVertex3f(half_cyclic_width,cyclic_height,-half_cyclic_width);
		glVertex3f(half_cyclic_width,0,-half_cyclic_width);
		// left 
		glColor3f(0.3,0.3,0.3);
		glVertex3f(-half_cyclic_width,0,-half_cyclic_width);
		glVertex3f(-half_cyclic_width,cyclic_height,-half_cyclic_width);
		glVertex3f(-half_cyclic_width,cyclic_height,half_cyclic_width);
		glVertex3f(-half_cyclic_width,0,half_cyclic_width);
		// right 
		glVertex3f(half_cyclic_width,0,-half_cyclic_width);
		glVertex3f(half_cyclic_width,cyclic_height,-half_cyclic_width);
		glVertex3f(half_cyclic_width,cyclic_height,half_cyclic_width);
		glVertex3f(half_cyclic_width,0,half_cyclic_width);
		// top
		glVertex3f(-half_cyclic_width,cyclic_height,-half_cyclic_width);
		glVertex3f(-half_cyclic_width,cyclic_height,half_cyclic_width);
		glVertex3f(half_cyclic_width,cyclic_height,half_cyclic_width);
		glVertex3f(half_cyclic_width,cyclic_height,-half_cyclic_width);

	glEnd();
	// grip
	glTranslatef(0,cyclic_height,0);
	float half_cyclic_grip_width = half_cyclic_width + 0.01f;
	float cyclic_grip_height = 0.05f;
	glBegin(GL_QUADS);
		// front
		glColor3f(0.1,0.1,0.1);
		glVertex3f(-half_cyclic_grip_width,0,half_cyclic_grip_width);
		glVertex3f(-half_cyclic_grip_width,cyclic_grip_height,half_cyclic_grip_width);
		glVertex3f(half_cyclic_grip_width,cyclic_grip_height,half_cyclic_grip_width);
		glVertex3f(half_cyclic_grip_width,0,half_cyclic_grip_width);
		// back
		glVertex3f(-half_cyclic_grip_width,0,-half_cyclic_grip_width);
		glVertex3f(-half_cyclic_grip_width,cyclic_grip_height,-half_cyclic_grip_width);
		glVertex3f(half_cyclic_grip_width,cyclic_grip_height,-half_cyclic_grip_width);
		glVertex3f(half_cyclic_grip_width,0,-half_cyclic_grip_width);
		// left 
		glVertex3f(-half_cyclic_grip_width,0,-half_cyclic_grip_width);
		glVertex3f(-half_cyclic_grip_width,cyclic_grip_height,-half_cyclic_grip_width);
		glVertex3f(-half_cyclic_grip_width,cyclic_grip_height,half_cyclic_grip_width);
		glVertex3f(-half_cyclic_grip_width,0,half_cyclic_grip_width);
		// right 
		glVertex3f(half_cyclic_grip_width,0,-half_cyclic_grip_width);
		glVertex3f(half_cyclic_grip_width,cyclic_grip_height,-half_cyclic_grip_width);
		glVertex3f(half_cyclic_grip_width,cyclic_grip_height,half_cyclic_grip_width);
		glVertex3f(half_cyclic_grip_width,0,half_cyclic_grip_width);
		// top
		glVertex3f(-half_cyclic_grip_width,cyclic_grip_height,-half_cyclic_grip_width);
		glVertex3f(-half_cyclic_grip_width,cyclic_grip_height,half_cyclic_grip_width);
		glVertex3f(half_cyclic_grip_width,cyclic_grip_height,half_cyclic_grip_width);
		glVertex3f(half_cyclic_grip_width,cyclic_grip_height,-half_cyclic_grip_width);

	glEnd();


	glPopMatrix();

	// --- Collective ---
	glColor3f(0.8,0.8,0.8);
	glPushMatrix();
	float collective_angle = world->helicopter.collective * 30;
	glTranslatef(0.3f,-0.5f,-0.5f);
	glRotatef(collective_angle,1,0,0);
	float collective_length = 0.5f;
	float half_collective_width = 0.005f;
	glBegin(GL_QUADS);
		// front
		glColor3f(0.4,0.4,0.4);
		glVertex3f(-half_collective_width,0,0);
		glVertex3f(-half_collective_width,0,-collective_length);
		glVertex3f(half_collective_width,0,-collective_length);
		glVertex3f(half_collective_width,0,0);
	glEnd();
	glColor3f(0.1,0.1,0.1);
	float half_collective_grip_width = half_collective_width + 0.01f;
	float collective_grip_length = 0.1f;
	glTranslatef(0,0,-collective_length);
	glBegin(GL_QUADS);
		// front
		glVertex3f(-half_collective_grip_width,0,0);
		glVertex3f(-half_collective_grip_width,0,-collective_grip_length);
		glVertex3f(half_collective_grip_width,0,-collective_grip_length);
		glVertex3f(half_collective_grip_width,0,0);
	glEnd();

	glPopMatrix();


	// --- Pedals ---
	glPushMatrix();
	glTranslatef(0,-0.45,-1.5f);
	float angle = world->helicopter.pedals * 50;
	glRotatef(angle,0,1,0);
	float pedals_half_length = 0.25f;
	float pedals_half_width = 0.005;
	float pedal_width = 0.1;
	float pedal_height = 0.12;
	glBegin(GL_QUADS);
		// bar
		glColor3f(0.4,0.4,0.4);
		glVertex3f(-pedals_half_length,-pedals_half_width,0);
		glVertex3f(-pedals_half_length,pedals_half_width,0);
		glVertex3f(pedals_half_length,pedals_half_width,0);
		glVertex3f(pedals_half_length,-pedals_half_width,0);
		// left pedal
		glColor3f(0.6,0.6,0.6);
		glVertex3f(-pedals_half_length,-pedals_half_width,0);
		glVertex3f(-pedals_half_length,pedal_height,0);
		glVertex3f(-pedals_half_length+pedal_width,pedal_height,0);
		glVertex3f(-pedals_half_length+pedal_width,-pedals_half_width,0);
		// right pedal
		glColor3f(0.6,0.6,0.6);
		glVertex3f(pedals_half_length,-pedals_half_width,0);
		glVertex3f(pedals_half_length,pedal_height,0);
		glVertex3f(pedals_half_length-pedal_width,pedal_height,0);
		glVertex3f(pedals_half_length-pedal_width,-pedals_half_width,0);
	glEnd();
	glPopMatrix();

	// --- View Throught window ---
	// helicopter orientation
	glRotatef(-orientation_x,1,0,0);
	glRotatef(-orientation_y,0,1,0);
	glRotatef(-orientation_z,0,0,1);

	// terrain
	glPushMatrix();
	glTranslatef(-position_x,-position_y,-position_z);
	terrain_representation.show(&(world->terrain),&(world->helicopter.position));
	glPopMatrix();

	// sky
	glPushMatrix();
	glTranslatef(0,-position_y,0);
	sky_representation.show(&(world->sky),&(world->helicopter.position));
	glPopMatrix();

	glPopMatrix();
}


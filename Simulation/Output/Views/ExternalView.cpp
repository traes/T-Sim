#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "ExternalView.h"

ExternalView::ExternalView(){
	terrain_representation = TerrainRepresentation();
	sky_representation = SkyRepresentation();
	helicopter_representation = HelicopterRepresentation();
}

void ExternalView::show(World* world,Camera* camera){
	glPushMatrix();

	float position_x = world->helicopter.position.x;
	float position_y = world->helicopter.position.y;
	float position_z = world->helicopter.position.z;

	float orientation_x = world->helicopter.orientation.x;
	float orientation_y = world->helicopter.orientation.y;
	float orientation_z = world->helicopter.orientation.z;

	// camera
	glTranslatef(0,0,-(camera->distance));
	glRotatef(camera->orientation.x,1,0,0);
	glRotatef(camera->orientation.y,0,1,0);
	glRotatef(camera->orientation.z,0,0,1);

	// terrain
	glPushMatrix();
	glTranslatef(-position_x,-position_y,-position_z);
	terrain_representation.show(&(world->terrain),&(world->helicopter.position));
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,-position_y,0);
	sky_representation.show(&(world->sky),&(world->helicopter.position));
	glPopMatrix();

	// helicopter
	glPushMatrix();
	glRotatef(orientation_x,1,0,0);
	glRotatef(orientation_y,0,1,0);
	glRotatef(orientation_z,0,0,1);
	helicopter_representation.show(&(world->helicopter));
	glPopMatrix();

	glPopMatrix();

}



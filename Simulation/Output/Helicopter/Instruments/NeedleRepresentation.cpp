#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "NeedleRepresentation.h"

NeedleRepresentation::NeedleRepresentation(){
}

void NeedleRepresentation::show(Needle* needle){
	float half_width = (needle->width)/2.0;
	glColor3f(1,1,1);
	glBegin(GL_QUADS);
	glVertex3f(-half_width,0,0);
	glVertex3f(-half_width,needle->length,0);
	glVertex3f(half_width,needle->length,0);
	glVertex3f(half_width,0,0);
	glEnd();
}

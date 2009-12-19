#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "NumberRepresentation.h"

NumberRepresentation::NumberRepresentation(){
}

void NumberRepresentation::show_horizontal_line(float length,float line_width){
	glBegin(GL_QUADS);
	glVertex3f(-length/2,-line_width/2,0);
	glVertex3f(-length/2,line_width/2,0);
	glVertex3f(length/2,line_width/2,0);
	glVertex3f(length/2,-line_width/2,0);
	glEnd();
}	

void NumberRepresentation::show_vertical_line(float length,float line_width){
	glBegin(GL_QUADS);
	glVertex3f(-line_width/2,-length/2,0);
	glVertex3f(line_width/2,-length/2,0);
	glVertex3f(line_width/2,length/2,0);
	glVertex3f(-line_width/2,length/2,0);
	glEnd();
}	

void NumberRepresentation::show_UH(float length, float line_width){
	glPushMatrix();
	glTranslatef(0,length/2,0);
	show_horizontal_line(length,line_width);
	glPopMatrix();
}

void NumberRepresentation::show_MH(float length, float line_width){
	show_horizontal_line(length,line_width);
}	
		
void NumberRepresentation::show_LH(float length, float line_width){
	glPushMatrix();
	glTranslatef(0,-length/2,0);
	show_horizontal_line(length,line_width);
	glPopMatrix();
}

void NumberRepresentation::show_LUV(float length, float line_width){
	glPushMatrix();
	glTranslatef(-length/2,length/4,0);
	show_vertical_line(length/2,line_width);
	glPopMatrix();
}

void NumberRepresentation::show_LLV(float length, float line_width){
	glPushMatrix();
	glTranslatef(-length/2,-length/4,0);
	show_vertical_line(length/2,line_width);
	glPopMatrix();
}

void NumberRepresentation::show_RUV(float length, float line_width){
	glPushMatrix();
	glTranslatef(length/2,length/4,0);
	show_vertical_line(length/2,line_width);
	glPopMatrix();
}

void NumberRepresentation::show_RLV(float length, float line_width){
	glPushMatrix();
	glTranslatef(length/2,-length/4,0);
	show_vertical_line(length/2,line_width);
	glPopMatrix();
}

void NumberRepresentation::show_digit(int digit,float horizontal_length, float vertical_length, float line_width){
	glColor3f(1,1,1);
	switch (digit) {
		case 0 :
			show_UH(horizontal_length,line_width);
			show_LH(horizontal_length,line_width);
			show_LUV(vertical_length,line_width);
			show_LLV(vertical_length,line_width);
			show_RUV(vertical_length,line_width);
			show_RLV(vertical_length,line_width);
			break;
		case 1 :
			show_RUV(vertical_length,line_width);
			show_RLV(vertical_length,line_width);
			break;
		case 2 :
			show_UH(horizontal_length,line_width);
			show_MH(horizontal_length,line_width);
			show_LH(horizontal_length,line_width);
			show_RUV(vertical_length,line_width);
			show_LLV(vertical_length,line_width);
			break;
		case 3 :
			show_UH(horizontal_length,line_width);
			show_MH(horizontal_length,line_width);
			show_LH(horizontal_length,line_width);
			show_RUV(vertical_length,line_width);
			show_RLV(vertical_length,line_width);
			break;
		case 4 :
			show_MH(horizontal_length,line_width);
			show_RUV(vertical_length,line_width);
			show_LUV(vertical_length,line_width);
			show_RLV(vertical_length,line_width);
			break;
		case 5 :
			show_UH(horizontal_length,line_width);
			show_MH(horizontal_length,line_width);
			show_LH(horizontal_length,line_width);
			show_LUV(vertical_length,line_width);
			show_RLV(vertical_length,line_width);
			break;
		case 6 :
			show_UH(horizontal_length,line_width);
			show_MH(horizontal_length,line_width);
			show_LH(horizontal_length,line_width);
			show_LUV(vertical_length,line_width);
			show_LLV(vertical_length,line_width);
			show_RLV(vertical_length,line_width);
			break;
		case 7 :
			show_UH(horizontal_length,line_width);
			show_RUV(vertical_length,line_width);
			show_RLV(vertical_length,line_width);
			break;
		case 8 :
			show_UH(horizontal_length,line_width);
			show_MH(horizontal_length,line_width);
			show_LH(horizontal_length,line_width);
			show_LUV(vertical_length,line_width);
			show_LLV(vertical_length,line_width);
			show_RUV(vertical_length,line_width);
			show_RLV(vertical_length,line_width);
			break;
		case 9 :
			show_UH(horizontal_length,line_width);
			show_MH(horizontal_length,line_width);
			show_LH(horizontal_length,line_width);
			show_LUV(vertical_length,line_width);
			show_RUV(vertical_length,line_width);
			show_RLV(vertical_length,line_width);
			break;
	};		
}

void NumberRepresentation::show(int number,float size){
	glPushMatrix();
	// properties
	float horizontal_length = size;
	float vertical_length = size;
	float line_width = size/5;
	float center_separation = horizontal_length * 1.5;

	// center number around current coordinates
	float number_of_digits = 0;
	for (int tmp = number; tmp > 10; tmp = tmp/10)
		number_of_digits++;
	glTranslatef((number_of_digits/2)*center_separation,0,0);
		
	// show digits	
	while(number > 9){
		show_digit(number%10,horizontal_length,vertical_length,line_width);
		glTranslatef(-center_separation,0,0);
		number /= 10;
	};
	show_digit(number,horizontal_length,vertical_length,line_width);
	glPopMatrix();
}


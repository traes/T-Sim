#include "Needle.h"

Needle::Needle(){
	origin = Vector3D();
	length = 0.05f;
	width = 0.003f;
	scale = 1.0f;
}

float Needle::get_angle(float value){
	return (value*scale);
}	


#include "Rotor.h"

Rotor::Rotor(){
	b = 4;
	c = 0.25f;
	r_h = 0.3f;
	r_t = 5.0f;
	rpm = 0;
	max_rpm = 400.0f;
	orientation = Vector3D(0,0,0);
	theta = 0;
}	

Rotor::Rotor(int b_arg,float c_arg,float r_h_arg,float r_t_arg){
	b = b_arg;
	c = c_arg;
	r_h = r_h_arg;
	r_t = r_t_arg;
	rpm = 0;
	max_rpm = 400.0f;
	orientation = Vector3D(0,0,0);
}	

void Rotor::update(float dt){
	float deg_per_second = (360.0f * rpm) / 60.0f;
	float deg_per_millisecond = deg_per_second / 1000.0f; 
	float deg_rotated = deg_per_millisecond * dt;
	orientation.y += deg_rotated;
}

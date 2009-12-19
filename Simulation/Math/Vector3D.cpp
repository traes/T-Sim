#include "Vector3D.h"
#include <iostream>

Vector3D::Vector3D(float x_arg,float y_arg,float z_arg) {
	x = x_arg;
	y = y_arg;
	z = z_arg;
}

Vector3D::Vector3D(float args[3]){
	x = args[0];
	y = args[1];
	z = args[2];
}

Vector3D::Vector3D(){
	x = y = z = 0.0f;
}	

void Vector3D::add(Vector3D *other_vector){
	x += other_vector->x;
	y += other_vector->y;
	z += other_vector->z;
}

void Vector3D::show(){
	std::cout << "[" << x << "," << y << "," << z << "]";
}

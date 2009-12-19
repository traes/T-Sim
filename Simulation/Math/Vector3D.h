#ifndef VECTOR3D_H
#define VECTOR3D_H

class Vector3D {
	public:
		Vector3D(float x_arg,float y_arg, float z_arg);
		Vector3D(float args[3]);
		Vector3D();
		float x;
		float y;
		float z;
		void show();
		void add(Vector3D *other_vector);
};

#endif

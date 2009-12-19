#include "SimpleFlightModel.h"

SimpleFlightModel::SimpleFlightModel(){
}

void SimpleFlightModel::update(Helicopter* helicopter,float dt){
	apply_controls(helicopter,dt);
	update_orientation(helicopter,dt);
	update_position(helicopter,dt);
	update_instruments(helicopter,dt);
	update_crashed(helicopter,dt);
}

void SimpleFlightModel::apply_controls(Helicopter* helicopter,float dt){
	Rotor* main_rotor = &(helicopter->main_rotor);
	Rotor* tail_rotor = &(helicopter->tail_rotor);
	main_rotor->rpm = helicopter->throttle * 360.0f;
	tail_rotor->rpm = main_rotor->rpm;
	main_rotor->update(dt);
	tail_rotor->update(dt);
	main_rotor->theta = helicopter->collective;
	tail_rotor->theta = helicopter->pedals;
}

void SimpleFlightModel::update_orientation(Helicopter* helicopter,float dt){
	helicopter->orientation.x = helicopter->cyclic_x * 90.0f;
	helicopter->orientation.z = helicopter->cyclic_z * 90.0f;
	helicopter->orientation.y = helicopter->pedals * 90.0f;
}

void SimpleFlightModel::update_position(Helicopter* helicopter,float dt){
	Vector3D* acceleration = &(helicopter->acceleration);
	Vector3D* velocity = &(helicopter->velocity);
	Vector3D* position = &(helicopter->position);
	Vector3D* orientation = &(helicopter->orientation);

	float gravity = -9.82f;

	// update acceleration (m/s)
	float traction = (helicopter->thrust * helicopter->throttle * helicopter->main_rotor.theta) / helicopter->mass;
	acceleration->x = sin(deg_to_rad(-orientation->z)) * traction;
	acceleration->y = cos(deg_to_rad(orientation->x)) * cos(deg_to_rad(orientation->z)) * traction;
	acceleration->y += gravity;
	acceleration->z = sin(deg_to_rad(orientation->x)) * traction;
	velocity->add(acceleration);

	// update displacement (m)
	float dt_seconds = dt/1000.0f; // dt (milliseconds)
	float delta_x = velocity->x * dt_seconds;
	float delta_y = velocity->y * dt_seconds;
	float delta_z = velocity->z * dt_seconds;

	// update position (m)
	position->x += delta_x;
	position->y += delta_y;
	position->z += delta_z;

	// helicopter stands on ground
	if (position->y < 2.1f){
		position->y = 2.1f;
		velocity->x = 0;
		velocity->y = 0;
		velocity->z = 0;
	};

	// operational ceiling
	if (position->y > 250.0f){
		position->y = 250.0f;
		velocity->y = 0.0f;
	};

	// max velocity
	if (velocity->x > 80.0f){
		velocity->x = 80.0f;
		acceleration->x = 0;
	};	
	
	if (velocity->x < -80.0f){
		velocity->x = -80.0f;
		acceleration->x = 0;
	};
	
	if (velocity->z > 80.0f){
		velocity->z = 80.0f;
		acceleration->z = 0;
	};

	if (velocity->z < -80.0f){
		velocity->z = -80.0f;
		acceleration->z = 0;
	};
}	

void SimpleFlightModel::update_instruments(Helicopter* helicopter,float dt){
	Vector3D* velocity = &(helicopter->velocity);
	Vector3D* position = &(helicopter->position);
	Vector3D* orientation = &(helicopter->orientation);
	Rotor* main_rotor = &(helicopter->main_rotor);
	InstrumentPanel* instrument_panel = &(helicopter->instrument_panel);
	instrument_panel->climb_indicator.value = velocity->y;
	instrument_panel->airspeed_indicator.value = abs((int)velocity->x) + abs((int)velocity->z); 
	instrument_panel->altitude_indicator.value = position->y;
	instrument_panel->rpm_indicator.value = (main_rotor->rpm/main_rotor->max_rpm)*100.0f; 
	instrument_panel->compass.heading = orientation->y;
	instrument_panel->artificial_horizon.roll = -orientation->z;
	instrument_panel->artificial_horizon.pitch = orientation->x;
}


void SimpleFlightModel::update_crashed(Helicopter* helicopter,float dt){
	//crashed = (position.y <= 0);
	helicopter->crashed = false;
}

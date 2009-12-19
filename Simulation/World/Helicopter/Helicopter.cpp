#include "Helicopter.h"

Helicopter::Helicopter(){
	// instruments
	instrument_panel = InstrumentPanel();
	// controls
	cyclic_x = 0.0f;
	cyclic_z = 0.0f;
	collective = 0.0f;
	throttle = 0.0f;
	pedals = 0.0f;
	// physical properties
	position = Vector3D();
	velocity = Vector3D();
	acceleration = Vector3D();
	orientation = Vector3D();
	thrust = 100000.0f; // (N)
	mass = 8000.0f; // (kg)
	crashed = false;
	// rotors
	main_rotor = Rotor(4,0.25f,0.3f,5.0f);
	tail_rotor = Rotor(2,0.10f,0.1f,1.5f);
	tail_rotor.orientation.z = 90.0f;
}	



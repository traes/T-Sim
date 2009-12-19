#include <SDL/SDL.h>
#include "InputManager.h"

InputManager::InputManager(){
	stop = false;
	delta_camera_distance = 1.0f;
	delta_camera_orientation = 5.0f;
	delta_helicopter_distance = 10.0f;
	delta_helicopter_orientation = 2.0f;
	delta_controls = 0.01f;
}

void InputManager::update(World* world,OutputManager* output_manager){
	unsigned char* key_table;
	SDL_PumpEvents();
	key_table = SDL_GetKeyState(NULL);	

	/* Simulation Controls */
	if (key_table[SDLK_RETURN])
		stop = 1;

	/* View Controls */
	if (key_table[SDLK_F10])
		output_manager->use_cockpit_3d_view();
	if (key_table[SDLK_F11])
		output_manager->use_cockpit_2d_view();
	if (key_table[SDLK_F12])
		output_manager->use_external_3d_view();

	/* Helicopter Controls */
	// cyclic
	if (key_table[SDLK_LEFT])
		increase_cyclic_z(world);
	if (key_table[SDLK_RIGHT])
		decrease_cyclic_z(world);
	if (key_table[SDLK_UP])
		decrease_cyclic_x(world);
	if (key_table[SDLK_DOWN])
		increase_cyclic_x(world);

	// collective	
	if (key_table[SDLK_c])
		decrease_collective(world);
	if (key_table[SDLK_v])
		increase_collective(world);

	// throttle
	if (key_table[SDLK_b])
		decrease_throttle(world);
	if (key_table[SDLK_n])
		increase_throttle(world);

	// pedals
	if (key_table[SDLK_w])
		decrease_pedals(world);
	if (key_table[SDLK_x])
		increase_pedals(world);

	/* Main Rotor Controls */
	if (key_table[SDLK_o])
		increase_main_rotor_rpm(world);
	if (key_table[SDLK_p])
		decrease_main_rotor_rpm(world);

	/* Move Helicopter */
	if (key_table[SDLK_a])
		increase_helicopter_position_x(world);
	if (key_table[SDLK_z])
		decrease_helicopter_position_x(world);
	if (key_table[SDLK_e])
		increase_helicopter_position_y(world);
	if (key_table[SDLK_r])
		decrease_helicopter_position_y(world);
	if (key_table[SDLK_t])
		increase_helicopter_position_z(world);
	if (key_table[SDLK_y])
		decrease_helicopter_position_z(world);

	/* Rotate Helicopter */
	if (key_table[SDLK_q])
		increase_helicopter_orientation_x(world);
	if (key_table[SDLK_s])
		decrease_helicopter_orientation_x(world);
	if (key_table[SDLK_d])
		increase_helicopter_orientation_y(world);
	if (key_table[SDLK_f])
		decrease_helicopter_orientation_y(world);
	if (key_table[SDLK_g])
		increase_helicopter_orientation_z(world);
	if (key_table[SDLK_h])
		decrease_helicopter_orientation_z(world);


	/* Camera Controls */	
	// camera distance from helicopter
	if (key_table[SDLK_F5])
		increase_camera_distance(output_manager);
	if (key_table[SDLK_F6])
		decrease_camera_distance(output_manager);

	// camera orientation
	if (key_table[SDLK_F1])
		increase_camera_orientation_y(output_manager);
	if (key_table[SDLK_F2])
		decrease_camera_orientation_y(output_manager);
	if (key_table[SDLK_F3])
		increase_camera_orientation_x(output_manager);
	if (key_table[SDLK_F4])
		decrease_camera_orientation_x(output_manager);

	if (key_table[SDLK_m])
		switch_wireframe(output_manager);


}

/* Helicopter Controls */

// cyclic

void InputManager::increase_cyclic_x(World* world){
	float* cyclic_x = &(world->helicopter.cyclic_x);
	*cyclic_x += delta_controls;
	if (*cyclic_x > 1.0f)
		*cyclic_x = 1.0f;
}

void InputManager::decrease_cyclic_x(World* world){
	float* cyclic_x = &(world->helicopter.cyclic_x);
	*cyclic_x -= delta_controls;
	if (*cyclic_x < -1.0f)
		*cyclic_x = -1.0f;
}

void InputManager::increase_cyclic_z(World* world){
	float* cyclic_z = &(world->helicopter.cyclic_z);
	*cyclic_z += delta_controls;
	if (*cyclic_z > 1.0f)
		*cyclic_z = 1.0f;
}

void InputManager::decrease_cyclic_z(World* world){
	float* cyclic_z = &(world->helicopter.cyclic_z);
	*cyclic_z -= delta_controls;
	if (*cyclic_z < -1.0f)
		*cyclic_z = -1.0f;
}

// collective

void InputManager::increase_collective(World* world){
	float* collective = &(world->helicopter.collective);
	*collective += delta_controls;
	if (*collective > 1.0f)
		*collective = 1.0f;
}

void InputManager::decrease_collective(World* world){
	float* collective = &(world->helicopter.collective);
	*collective -= delta_controls;
	if (*collective < -1.0f)
		*collective = -1.0f;
}

// throttle

void InputManager::increase_throttle(World* world){
	float* throttle = &(world->helicopter.throttle);
	*throttle += delta_controls;
	if (*throttle > 1.0f)
		*throttle = 1.0f;
}

void InputManager::decrease_throttle(World* world){
	float* throttle = &(world->helicopter.throttle);
	*throttle -= delta_controls;
	if (*throttle < 0.0f)
		*throttle = 0.0f;
}

// pedals

void InputManager::increase_pedals(World* world){
	float* pedals = &(world->helicopter.pedals);
	*pedals += delta_controls;
	if (*pedals > 1.0f)
		*pedals = 1.0f;
}

void InputManager::decrease_pedals(World* world){
	float* pedals = &(world->helicopter.pedals);
	*pedals -= delta_controls;
	if (*pedals < -1.0f)
		*pedals = -1.0f;
}		

/* Direct Rotor Controls */

void InputManager::increase_main_rotor_rpm(World* world){
	world->helicopter.main_rotor.rpm += 1;
}	

void InputManager::decrease_main_rotor_rpm(World* world){
	world->helicopter.main_rotor.rpm -= 1;
	if (world->helicopter.main_rotor.rpm < 0)
		world->helicopter.main_rotor.rpm = 0;
}	

/* Move Helicopter */

void InputManager::increase_helicopter_position_x(World* world){
	world->helicopter.position.x += delta_helicopter_distance;
}

void InputManager::decrease_helicopter_position_x(World* world){
	world->helicopter.position.x -= delta_helicopter_distance;
}

void InputManager::increase_helicopter_position_y(World* world){
	world->helicopter.position.y += delta_helicopter_distance;
}

void InputManager::decrease_helicopter_position_y(World* world){
	world->helicopter.position.y -= delta_helicopter_distance;
}

void InputManager::increase_helicopter_position_z(World* world){
	world->helicopter.position.z += delta_helicopter_distance;
}

void InputManager::decrease_helicopter_position_z(World* world){
	world->helicopter.position.z -= delta_helicopter_distance;
}

/* Rotate Helicopter */

void InputManager::increase_helicopter_orientation_x(World* world){
	world->helicopter.orientation.x += delta_helicopter_orientation;
}

void InputManager::decrease_helicopter_orientation_x(World* world){
	world->helicopter.orientation.x -= delta_helicopter_orientation;
}

void InputManager::increase_helicopter_orientation_y(World* world){
	world->helicopter.orientation.y += delta_helicopter_orientation;
}

void InputManager::decrease_helicopter_orientation_y(World* world){
	world->helicopter.orientation.y -= delta_helicopter_orientation;
}

void InputManager::increase_helicopter_orientation_z(World* world){
	world->helicopter.orientation.z += delta_helicopter_orientation;
}

void InputManager::decrease_helicopter_orientation_z(World* world){
	world->helicopter.orientation.z -= delta_helicopter_orientation;
}


/* Camera Controls */

// camera distance from helicopter

void InputManager::increase_camera_distance(OutputManager* output_manager){
	output_manager->camera.distance += delta_camera_distance;
}

void InputManager::decrease_camera_distance(OutputManager* output_manager){
	output_manager->camera.distance -= delta_camera_distance;
}

// camera orientation

void InputManager::increase_camera_orientation_x(OutputManager* output_manager){
	output_manager->camera.orientation.x += delta_camera_orientation;
}

void InputManager::decrease_camera_orientation_x(OutputManager* output_manager){
	output_manager->camera.orientation.x -= delta_camera_orientation;
}	

void InputManager::increase_camera_orientation_y(OutputManager* output_manager){
	output_manager->camera.orientation.y += delta_camera_orientation;
}

void InputManager::decrease_camera_orientation_y(OutputManager* output_manager){
	output_manager->camera.orientation.y -= delta_camera_orientation;
}

// enable/disable wireframe

void InputManager::switch_wireframe(OutputManager* output_manager){
}	


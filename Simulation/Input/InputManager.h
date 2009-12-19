#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include "World.h"
#include "OutputManager.h"
#include "Vector3D.h"

class InputManager {
	public:
		InputManager();
		bool stop;
		void update(World* world,OutputManager* output_manager);
	private:
		/* input sensitivity */
		float delta_camera_distance;
		float delta_camera_orientation;
		float delta_helicopter_distance;
		float delta_helicopter_orientation;
		float delta_controls;
		/* Helicopter controls */
		// cyclic
		void increase_cyclic_x(World* world);
		void decrease_cyclic_x(World* world);
		void increase_cyclic_z(World* world);
		void decrease_cyclic_z(World* world);
		// collective
		void increase_collective(World* world);
		void decrease_collective(World* world);
		// throttle
		void increase_throttle(World* world);
		void decrease_throttle(World* world);
		// pedals
		void increase_pedals(World* world);
		void decrease_pedals(World* world);
		
		/* Direct Rotor Controls */
		void increase_main_rotor_rpm(World* world);
		void decrease_main_rotor_rpm(World* world);

		/* Move Helicopter */
		void increase_helicopter_position_x(World* world);
		void decrease_helicopter_position_x(World* world);
		void increase_helicopter_position_y(World* world);
		void decrease_helicopter_position_y(World* world);
		void increase_helicopter_position_z(World* world);
		void decrease_helicopter_position_z(World* world);

		/* Rotate Helicopter */
		void increase_helicopter_orientation_x(World* world);
		void decrease_helicopter_orientation_x(World* world);
		void increase_helicopter_orientation_y(World* world);
		void decrease_helicopter_orientation_y(World* world);
		void increase_helicopter_orientation_z(World* world);
		void decrease_helicopter_orientation_z(World* world);

		/* Camera controls */
		// distance from helicopter
		void increase_camera_distance(OutputManager* output_manager);
		void decrease_camera_distance(OutputManager* output_manager);
		// orientation
		void increase_camera_orientation_x(OutputManager* output_manager);
		void decrease_camera_orientation_x(OutputManager* output_manager);
		void increase_camera_orientation_y(OutputManager* output_manager);
		void decrease_camera_orientation_y(OutputManager* output_manager);
		// enable/disable wireframe
		void switch_wireframe(OutputManager* output_manager);
};
#endif


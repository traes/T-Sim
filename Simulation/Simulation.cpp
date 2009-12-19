#include <iostream>
#include <SDL/SDL.h>
#include "Simulation.h"

Simulation::Simulation(){
	input_manager = InputManager();
	output_manager = OutputManager();
	world = World();
	running = true;
}	

void Simulation::run(){
	Uint32 min_elapsed_time = (Uint32) 1000.0/60; // max 60 frames/second
	Uint32 elapsed_time = min_elapsed_time;
	Uint32 time_before_update = SDL_GetTicks(); 
	Uint32 time_after_update = 0;
	while(running){
		// stop simulation
		if (input_manager.stop)
			running = false;
		if (world.helicopter.crashed)
			running = false;
		
		// run simulation update
		input_manager.update(&world,&output_manager);
		world.update(elapsed_time);
		output_manager.update(&world);

		// timing
		time_after_update = SDL_GetTicks();
		while ((time_after_update - time_before_update) < min_elapsed_time){
			time_after_update = SDL_GetTicks();
		};	
		elapsed_time = time_after_update - time_before_update;
		time_before_update = SDL_GetTicks();
	};
}

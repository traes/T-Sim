#ifndef SIMULATION_H
#define SIMULATION_H

#include "Input/InputManager.h"
#include "Output/OutputManager.h"
#include "World/World.h"

class Simulation {
	public:
		Simulation();
		InputManager input_manager;
		OutputManager output_manager;
		World world;
		bool running;
		void run();
};		

#endif

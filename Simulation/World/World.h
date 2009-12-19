#ifndef WORLD_H
#define WORLD_H

#include "Helicopter.h"
#include "Terrain.h"
#include "Sky.h"
#include "SimpleFlightModel.h"

class World {
	public:
		World();
		Helicopter helicopter;
		SimpleFlightModel simple_flight_model;
		Terrain terrain;
		Sky sky;
		void update(int dt);
};	

#endif

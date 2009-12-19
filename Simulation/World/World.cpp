#include <iostream>

#include "World.h"

World::World(){
	helicopter = Helicopter();
	terrain = Terrain();
	sky = Sky();
	simple_flight_model = SimpleFlightModel();
	helicopter.position.x = 0;
	helicopter.position.z = 0;
	helicopter.position.y = terrain.height(helicopter.position.x,helicopter.position.z);
}

void World::update(int dt){
	simple_flight_model.update(&helicopter,dt);
}


#ifndef EXTERNAL_VIEW_H
#define EXTERNAL_VIEW_H

#include "World.h"
#include "Camera.h"
#include "TerrainRepresentation.h"
#include "SkyRepresentation.h"
#include "HelicopterRepresentation.h"

class ExternalView {
	public:
		ExternalView();
		void show(World* world,Camera* camera);
	private:	
		TerrainRepresentation terrain_representation;	
		HelicopterRepresentation helicopter_representation;
		SkyRepresentation sky_representation;

};

#endif

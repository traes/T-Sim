#ifndef COCKPIT_VIEW_H
#define COCKPIT_VIEW_H

#include "World.h"
#include "Camera.h"
#include "InstrumentPanelRepresentation.h"
#include "TerrainRepresentation.h"
#include "SkyRepresentation.h"
#include "RotorRepresentation.h"

class CockpitView {
	public:
		CockpitView();
		void show(World* world,Camera* camera);
	private:
		InstrumentPanelRepresentation instrument_panel_representation;
		TerrainRepresentation terrain_representation;
		RotorRepresentation rotor_representation;
		SkyRepresentation sky_representation;
};

#endif

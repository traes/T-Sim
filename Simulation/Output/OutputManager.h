#ifndef OUTPUT_MANAGER_H
#define OUTPUT_MANAGER_H

#include "World.h"
#include "Camera.h"
#include "ExternalView.h"
#include "CockpitView.h"
#include "InstrumentsView.h"

enum {USE_EXTERNAL_3D_VIEW, USE_COCKPIT_3D_VIEW, USE_COCKPIT_2D_VIEW};

class OutputManager{
	public:
		OutputManager();
		Camera camera;
		void update(World* world);
		void use_external_3d_view();
		void use_cockpit_3d_view();
		void use_cockpit_2d_view();
	private:
		ExternalView external_view;
		CockpitView cockpit_view;
		InstrumentsView instruments_view;
		int current_view;
		void external_3d_view(World* world);
		void cockpit_3d_view(World* world);
		void cockpit_2d_view(World* world);
		void start_opengl();
};		

#endif

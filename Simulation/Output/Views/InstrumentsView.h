#ifndef INSTRUMENTS_VIEW_H
#define INSTRUMENTS_VIEW_H

#include "InstrumentPanelRepresentation.h"
#include "World.h"
#include "Camera.h"

class InstrumentsView {
	public:
		InstrumentsView();
		void show(World* world,Camera* camera);
	private:
		InstrumentPanelRepresentation instrument_panel_representation;
};

#endif

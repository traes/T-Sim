#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "InstrumentsView.h"

InstrumentsView::InstrumentsView(){
	instrument_panel_representation = InstrumentPanelRepresentation();
}

void InstrumentsView::show(World* world,Camera* camera){
	instrument_panel_representation.show(&(world->helicopter.instrument_panel));
}

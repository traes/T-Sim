#ifndef ARTIFICIAL_HORIZON__VIEWER_H
#define ARTIFICIAL_HORIZON__VIEWER_H

#include "Conversions.h"
#include "ArtificialHorizon.h"
#include "InstrumentRepresentation.h"

/*
    ------------------
   |                  |
   |      Blue        |
   |                  |
   |                  |
1->|------------------|<- 2
   |                  |
   |      Orange      |
   |                  |
   |                  |
    ------------------

(1) border_left
(2) border_right

*/


class ArtificialHorizonRepresentation : public InstrumentRepresentation {
	public:	
		ArtificialHorizonRepresentation();
		void show(ArtificialHorizon* artificial_horizon);
		float width;
		float height;
	private:
		void show_horizon(ArtificialHorizon* artificial_horizon);
		void show_cover(ArtificialHorizon* artificial_horizon);
		float pitch_border_delta(float pitch);
};

#endif

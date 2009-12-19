/*

The terrain lies in the X,Z-plane.
It is divided into several square tiles.
Only the revelant tiles are rendered, depending on given (X,Z)-coordinates.
Therefore, the tile that contains this (X,Z)-coordinates has to be found.
This tile is the tile which center is nearest to the given coordinates.

To select this tile, we determine how many half-tile lengths the
 given coordinates are removed from the origin (0,0). 
This has to be done for both axis. 

The number of tile-lengths can be calculated from this number of half-tile lengths.
Keep in mind that the center of tile in the middle of the terrain lies on the origin.
The borders of the tiles are thus situated at multiples of half-tile lengths.

It is only necessary to select the next tile when the number of half-tile lengths is odd.

This diagram illustrates the division of the tiles along the Z-axis,
 the division along the X-axis in analog.

                         ^ X                                  
                         .                                   
                         .   tile                                
                         .   dimension                                
          |     |     |  .  |<--->|     |                    
          |  :  |  :  |  .  |  :  |  :  |                     
          |  :  |  :  |  .  |  :  |  :  |                     
          |  :  |  :  |  .  |  :  |  :  |                     
          |  :  |  :  |  .  |  :  |  :  |                     
          |  :  |  :  |  .  |  :  |  :  |         Z          
. . . . . |. :. |. :. |. . .|. :. |. :. |. . . . . >                                                            
          |  :  |  :  |  .  |  :  |  :  |                     
Half tile |-4:-3|-2:-1|-0. 0| 1: 2| 3: 4|
          |  :  |  :  |  .  |  :  |  :  |
     tile | -2  | -1  |  0  |  1  |  2  |
                         .                                   
                         .                                   
                         .                                   
                                                            
*/

#ifndef TERRAIN_H
#define TERRAIN_H

#include <vector>
#include "TerrainTile.h"
#include "TerrainTileStore.h"

class Terrain{
	public:
		Terrain();
		TerrainTileStore tiles;
		float height(float x,float z);
};

#endif

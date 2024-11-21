/* The Tile structure contains two variables, one for color and one for event.
 - Tile type varies based on the numeric value of event.
*/

#define TILE_H

struct Tile{
    char color;
    int event;
};
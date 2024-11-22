#include "Tile.h"
#include "Player.h"
using namespace std;

Tile::Tile()
{
    color = 'G'; // grassland
    event = -1;  // no event set
}
Tile::Tile(char col, int eve)
{
    color = col;
    event = eve;
}
char Tile::getColor()
{
    return color;
}
void Tile::setColor(char col)
{
    color = col;
}
int Tile::getEvent()
{
    return event;
}
void Tile::setEvent(int eve)
{
    event = eve;
}
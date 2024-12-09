//Worked on by: Alec Ebert, Alex Class

#pragma once
#include "Tile.h"
#include "Player.h"

class Board
{
private:
    static const int _BOARD_SIZE = 52;
    Tile _tiles[2][_BOARD_SIZE];
    static const int _MAX_PLAYERS = 10;
    int _player_count;
    int _player_position[_MAX_PLAYERS];

    void displayTile(int track_index, int pos, Player players[], const int NUM_PLAYERS);
    void initializeTiles(int player_index);
    bool isPlayerOnTile(int pos, Player players[], const int NUM_PLAYERS);

public:
    Board();
    Board(int player_c);
    void displayTrack(int track_index, Player players[], const int NUM_PLAYERS);
    void initializeBoard();
    void displayBoard(Player players[], const int NUM_PLAYERS);
    bool movePlayer(int player_index);
    int getPlayerPosition(int player_index) const;
    Tile getTile(int track, int position); // returns tile value
};

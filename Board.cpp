// Worked on by: Alec Ebert, Alex Class

#include "Board.h"
#include "Tile.h"
#include "Player.h"
#include <iostream>
#include <string>

#define RED "\033[48;2;230;10;10m"
#define GREEN "\033[48;2;34;139;34m" /* Grassy Green (34,139,34) */
#define BLUE "\033[48;2;10;10;230m"
#define PINK "\033[48;2;255;105;180m"
#define BROWN "\033[48;2;139;69;19m"
#define PURPLE "\033[48;2;128;0;128m"
#define ORANGE "\033[48;2;230;115;0m" /* Orange (230,115,0) */
#define GREY "\033[48;2;128;128;128m" /* Grey (128,128,128) */
#define RESET "\033[0m"

using namespace std;

// Initializes two tracks
void Board::initializeBoard()
{
    // Seed random number generator in your main function once
    for (int i = 0; i < 2; i++)
    {
        initializeTiles(i); // This ensures each lane has a unique tile distribution
    }
}

#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

// Distributes tiles into a 2D array, weighted by game rules
void Board::initializeTiles(int laneIndex)
{
    Tile temp;
    int green_count = 0;
    int total_tiles = _BOARD_SIZE;

    // Keep track of green tile positions to ensure we place exactly 30 greens

    for (int i = 0; i < total_tiles; i++)
    {
        if (laneIndex == 0)
        {
            if (i == total_tiles - 1)
            {
                // Set the last tile as Orange for "Pride Rock"
                temp.setColor('O');
            }
            else if (i == 0)
            {
                // Set the last tile as Grey for "Starting Point"
                temp.setColor('Y');
            }
            else if (green_count < 30 && (rand() % (total_tiles - i) < 30 - green_count))
            {
                temp.setColor('G');
                green_count++;
            }
            else
            {
                int color_choice = rand() % 100; // Randomly assign one of the other colors: Blue, Pink, Brown, Red, Purple (weighted)
                if (i < (total_tiles / 2))
                { // first half
                    if (color_choice <= 25)
                    {
                        temp.setColor('R'); // graveyard
                    }
                    else if (color_choice > 25 && color_choice <= 50)
                    {
                        temp.setColor('N'); // hyenas
                    }
                    else if (color_choice > 50 && color_choice <= 70)
                    {
                        temp.setColor('P'); // advisor
                    }
                    else if (color_choice > 70 && color_choice <= 95)
                    {
                        temp.setColor('U'); // challenge
                    }
                    else if (color_choice > 95)
                    {
                        temp.setColor('B'); // oasis
                    }
                    else
                    {
                        cout << "you balanced your colors wrong; first half, first row" << endl;
                    }
                }
                else
                { // second half
                    if (color_choice <= 15)
                    {
                        temp.setColor('R'); // graveyard
                    }
                    else if (color_choice > 15 && color_choice <= 30)
                    {
                        temp.setColor('N'); // hyenas
                    }
                    else if (color_choice > 30 && color_choice <= 50)
                    {
                        temp.setColor('P'); // advisor
                    }
                    else if (color_choice > 50 && color_choice <= 75)
                    {
                        temp.setColor('U'); // challenge
                    }
                    else if (color_choice > 75)
                    {
                        temp.setColor('B'); // oasis
                    }
                    else
                    {
                        cout << "you balanced your colors wrong; second half first row" << endl;
                    }
                }
            }
        }
        else
        {
            if (i == total_tiles - 1)
            {
                // Set the last tile as Orange for "Pride Rock"
                temp.setColor('O');
            }
            else if (i == 0)
            {
                // Set the last tile as Grey for "Starting Point"
                temp.setColor('Y');
            }
            else if (green_count < 30 && (rand() % (total_tiles - i) < 30 - green_count))
            {
                temp.setColor('G');
                green_count++;
            }
            else
            {
                int color_choice = rand() % 100; // Randomly assign one of the other colors: Blue, Pink, Brown, Red, Purple (weighted)
                if (i < (total_tiles / 2))
                { // first half
                    if (color_choice <= 20)
                    {
                        temp.setColor('R'); // graveyard
                    }
                    else if (color_choice > 20 && color_choice <= 40)
                    {
                        temp.setColor('N'); // hyenas
                    }
                    else if (color_choice > 40 && color_choice <= 55)
                    {
                        temp.setColor('P'); // advisor
                    }
                    else if (color_choice > 55 && color_choice <= 80)
                    {
                        temp.setColor('U'); // challenge
                    }
                    else if (color_choice > 80)
                    {
                        temp.setColor('B'); // oasis
                    }
                    else
                    {
                        cout << "you balanced your colors wrong, first half, second row" << endl;
                    }
                }
                else
                { // second half
                    if (color_choice <= 20)
                    {
                        temp.setColor('R'); // graveyard
                    }
                    else if (color_choice > 20 && color_choice <= 40)
                    {
                        temp.setColor('N'); // hyenas
                    }
                    else if (color_choice > 40 && color_choice <= 55)
                    {
                        temp.setColor('P'); // advisor
                    }
                    else if (color_choice > 55 && color_choice <= 70)
                    {
                        temp.setColor('U'); // challenge
                    }
                    else if (color_choice > 70)
                    {
                        temp.setColor('B'); // oasis
                    }
                    else
                    {
                        cout << "you balanced your colors wrong, second half second row" << endl;
                    }
                }
            }
        }

        // Assign the tile to the board for the specified lane
        _tiles[laneIndex][i] = temp;
    }
}

// Board::Board()
// {
//     _player_count = 1;

//     // Initialize player position
//     _player_position[0] = 0;

//     // Initialize tiles
//     initializeTiles();
// }

// Initializes a board for every player currently in the game
Board::Board(const int NUM_PLAYERS)
{
    if (NUM_PLAYERS > _MAX_PLAYERS)
    {
        _player_count = _MAX_PLAYERS;
    }
    else
    {
        _player_count = NUM_PLAYERS;
    }

    // Initialize player position
    for (int i = 0; i < _player_count; i++)
    {
        _player_position[i] = 0;
    }

    // Initialize tiles

    initializeBoard();
}

// Returns true if a player is on a tile, false otherwise.
bool Board::isPlayerOnTile(int pos, Player players[], const int NUM_PLAYERS)
{
    for (int i = 0; i < NUM_PLAYERS; i++)
    {
        if (players[i].getPosition() == pos)
        {
            return true;
        }
    }
    return false;
}

// Prints a single tile, in color, to the terminal.
void Board::displayTile(int track_index, int pos, Player players[], const int NUM_PLAYERS)
{
    // string space = "                                       ";
    string color = "";

    // Template for displaying a tile: <line filler space> <color start> |<player symbol or blank space>| <reset color> <line filler space> <endl>

    // Determine color to display
    char currentTileColor = _tiles[track_index][pos].getColor();

    switch (currentTileColor)
    {
    case 'R':
        color = RED;
        break;
    case 'G':
        color = GREEN;
        break;
    case 'B':
        color = BLUE;
        break;
    case 'U':
        color = PURPLE;
        break;
    case 'N':
        color = BROWN;
        break;
    case 'P':
        color = PINK;
        break;
    case 'O':
        color = ORANGE;
        break;
    case 'Y':
        color = GREY;
        break;
    default:
        color = GREEN;
    }

    if (isPlayerOnTile(pos, players, NUM_PLAYERS))
    {
        cout << color << "|";
        for (int i = 0; i < NUM_PLAYERS; i++)
        {
            if (players[i].getPosition() == pos && track_index == players[i].getTrained()) // print out all players on the tile
            { 
                cout << (i + 1);
            }
            else if (players[i].getPosition() == pos)
            {
                cout << " ";
            }
        }
        cout << "|" << RESET;
    }
    else
    {
        cout << color << "| |" << RESET;
    }
}

// Displays a single track
void Board::displayTrack(int track_index, Player players[], const int NUM_PLAYERS)
{
    for (int i = 0; i < _BOARD_SIZE; i++)
    {
        displayTile(track_index, i, players, NUM_PLAYERS);
    }
    cout << endl;
}

// Displays the boards (both tracks)
void Board::displayBoard(Player players[], const int NUM_PLAYERS)
{
    for (int i = 0; i < 2; i++)
    {
        displayTrack(i, players, NUM_PLAYERS);
        if (i == 0)
        {
            cout << endl; // Add an extra line between the two lanes
        }
    }
}

// Moves a player along the board by one tile. Returns true if the last tile is reached.
bool Board::movePlayer(int player_index)
{
    // Increment player position
    _player_position[player_index]++;
    if (_player_position[player_index] == _BOARD_SIZE - 1)
    {
        // Player reached last tile
        return true;
    }
    return false;
}

// Gets a player's position. Returns -1 if player is not found.
int Board::getPlayerPosition(int player_index) const // this const is freaking me out but im leaving it in case it was intentional
{
    if (player_index >= 0 && player_index <= _player_count)
    {
        return _player_position[player_index];
    }
    return -1;
}

Tile Board::getTile(int track, int position){
    return _tiles[track][position];
}



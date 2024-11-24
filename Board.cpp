#include "Board.h"
#include "Tile.h"
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
        } else {
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

Board::Board(int player_count)
{
    if (player_count > _MAX_PLAYERS)
    {
        _player_count = _MAX_PLAYERS;
    }
    else
    {
        _player_count = player_count;
    }

    // Initialize player position
    for (int i = 0; i < _player_count; i++)
    {
        _player_position[i] = 0;
    }

    // Initialize tiles

    initializeBoard();
}

bool Board::isPlayerOnTile(int player_index, int pos)
{
    if (_player_position[player_index] == pos)
    {
        return true;
    }
    return false;
}

void Board::displayTile(int player_index, int pos)
{
    // string space = "                                       ";
    string color = "";
    int player = isPlayerOnTile(player_index, pos);

    // Template for displaying a tile: <line filler space> <color start> |<player symbol or blank space>| <reset color> <line filler space> <endl>

    // Determine color to display
    if (_tiles[player_index][pos].getColor() == 'R')
    {
        color = RED;
    }
    else if (_tiles[player_index][pos].getColor() == 'G')
    {
        color = GREEN;
    }
    else if (_tiles[player_index][pos].getColor() == 'B')
    {
        color = BLUE;
    }
    else if (_tiles[player_index][pos].getColor() == 'U')
    {
        color = PURPLE;
    }
    else if (_tiles[player_index][pos].getColor() == 'N')
    {
        color = BROWN;
    }
    else if (_tiles[player_index][pos].getColor() == 'P')
    {
        color = PINK;
    }
    else if (_tiles[player_index][pos].getColor() == 'O')
    {
        color = ORANGE;
    }
    else if (_tiles[player_index][pos].getColor() == 'Y')
    {
        color = GREY;
    }

    if (player == true)
    {
        cout << color << "|" << (player_index + 1) << "|" << RESET;
    }
    else
    {
        cout << color << "| |" << RESET;
    }
}

void Board::displayTrack(int player_index)
{
    for (int i = 0; i < _BOARD_SIZE; i++)
    {
        displayTile(player_index, i);
    }
    cout << endl;
}

void Board::displayBoard()
{
    for (int i = 0; i < 2; i++)
    {
        displayTrack(i);
        if (i == 0)
        {
            cout << endl; // Add an extra line between the two lanes
        }
    }
}

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

int Board::getPlayerPosition(int player_index) const
{
    if (player_index >= 0 && player_index <= _player_count)
    {
        return _player_position[player_index];
    }
    return -1;
}
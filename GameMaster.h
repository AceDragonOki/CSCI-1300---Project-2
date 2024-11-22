#pragma once
#include "Board.h"
#include "Player.h"
#include "Tile.h"
#include <iostream>
#include <string>

using namespace std;


class GameMaster
{
public:
    Player promptForChosingCharacter(Player players[], const int PLAYERS_SIZE, int playerIndex); // Prompts the user to pick a character from the available characters in character.txt.
    // Also ensures the character they choose is not picked by any other players.
    int spinTheWheel(Player player); // returns a random value along with some print statements for flavor
    Player chooseAPath(Player player); // Prompts the user to choose a path
    void mainMenu(Player players[], const int PLAYERS_SIZE); // prints out a menu with all the players and their stats
};
//Worked on by: Alec Ebert, Alex Class

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
    void promptForChoosingCharacters(Player players[], const int PLAYERS_SIZE); // Prompts the user to pick a character from the available characters in character.txt. Also ensures the character they choose is not picked by any other players.
    int spinTheWheel(); // Returns a random number between 1 and 6, with some flavor text.
    Player chooseAPath(Player player); // Prompts the user to choose a path
    void mainMenu(Player players[], const int PLAYERS_SIZE); // Prints out a menu with all the players and their stats
    bool validateInt(string number); // Checks if a string is an integer (so stoi can be used safely)
    int split(string input_string, char separator, string arr[], const int ARR_SIZE); // Parses an int into a string based on a delimiter, then returns the size. Returns -1 if no delimiter is found.
    void parseFileInto2DArray(string arr[], string fileName, const int NUM_LINES, const int NUM_ARRAY_ITEMS);
};
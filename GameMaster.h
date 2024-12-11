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
    void characterCreation(Player players[], const int NUM_PLAYERS, string advisors[][10], const int NUM_ADVISORS); // Prompts the user to pick a character from the available characters in character.txt. Also ensures the character they choose is not picked by any other players, and assigns the player an ID (playerNumber).
    int spinTheWheel(); // Returns a random number between 1 and 6, with some flavor text.
    Player chooseAPath(Player player); // Prompts the user to choose a path
    void mainMenu(Player players[], const int NUM_PLAYERS); // Prints out a menu with all the players and their stats
    bool validateInt(string number); // Checks if a string is an integer (so stoi can be used safely)
    int split(string input_string, char separator, string arr[], const int ARR_SIZE); // Parses an int into a string based on a delimiter, then returns the size. Returns -1 if no delimiter is found.
    void parseFileInto2DArray(string arr[][10], string fileName, const int NUM_ARRAY_ITEMS); // Reads a txt file and parses it into a passed-in 2D array. Note that the passed-in array must have width 10, and that fileName should include the file extension (e.g. "character.txt"). Array size of 10 was chosen arbitrarily, but should fit all cases.
    void writeGameDataToFile(Player players[], const int NUM_PLAYERS); // Writes endgame data to a file
    string pickABuild(string builds[][10], const int NUMBER_OF_BUILDS); // Happens during character creation. Reads from builds array and prints out the options, then has the player select the option they want. Returns the name of the build they choose.
    int decideNumPlayers(); // Prompts the users to select the number of players in the game. Returns the number of players selected.
    int pickAnAge(); // Prompts the user to select an age for their character.
    int evaluateScore(Player player); //calculates the final score for the player
    Player movementAction(int playerNumber, Board board, Player players[], int NUM_PLAYERS,string events[][10], const int NUM_EVENTS, string riddles[][10], const int NUM_RIDDLES);
    Player playerTurn(int playerNumber, Board board, Player players[], int NUM_PLAYERS, string events[][10], const int NUM_EVENTS, string riddles[][10], const int NUM_RIDDLES);
    bool gameEndCondition(Player players[], int NUM_PLAYERS);
};

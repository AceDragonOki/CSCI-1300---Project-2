// Worked on by: Alec Ebert, Alex Class

#include "Board.h"
#include "Player.h"
#include "Tile.h"
#include "GameMaster.h"
#include <iostream>
#include <fstream>

using namespace std;

// Checks if a string is an integer (so stoi can be used safely)
bool GameMaster::validateInt(string number)
{

    for (int i = 0; i < (int)number.length(); i++)
    {

        if (number[i] == '-')
        {
            if (i != 0)
            {
                return false;
            }
        }
        else if (!(int(number[i]) >= 48 && int(number[i]) <= 57))
        {
            return false;
        }
    }
    return true;
}

// Parses an int into a string based on a delimiter, then returns the size. Returns -1 if no delimiter is found.
int GameMaster::split(string input_string, char separator, string arr[], const int ARR_SIZE)
{
    int starting = 0;
    int x = 0;
    for (int i = 0; i < int(input_string.length()); i++)
    {
        if (input_string[i] == separator)
        {
            if (x < ARR_SIZE)
            {
                arr[x] = input_string.substr(starting, i - starting);
                starting = i + 1;
                x++;
            }
            else
            {
                return -1;
            }
        }
    }
    if (x < ARR_SIZE)
    {
        arr[x] = input_string.substr(starting, int(input_string.length()) - starting);
        x++;
    }
    else
    {
        return -1;
    }
    return x;
}

void GameMaster::parseFileInto2DArray(string arr[], string fileName, const int NUM_LINES, const int NUM_ARRAY_ITEMS)
{
    // take in 1D array
    // start looping through file (accessed with fileName)
    // for each line, construct a new 1D array populated with the contents of the line of the file
    // finally, pass the new 1D array into the passed-in 1D array
    // return 2D array???
    // google "C++ function to turn a file into a 2D array" and see how they deal with how shitty arrays are here
}

// Prompts the user to pick a character from the available characters in character.txt. Also ensures the character they choose is not picked by any other players.
void GameMaster::promptForChoosingCharacters(Player players[], const int PLAYERS_SIZE)
{

    string chosenPlayerName;
    for (int i = 0; i < PLAYERS_SIZE; i++)
    {

        cout << "Player " << i + 1 << ": Choose your Character (Write in the name)" << endl;
        cin >> chosenPlayerName;

        bool allNamesChecked = false;
        bool needToPickANewName = false;

        while (!allNamesChecked)
        {
            for (int j = 0; j < PLAYERS_SIZE; j++)
            {
                if (needToPickANewName){
                    cout << "Please choose a name not already in use." << endl;
                    cin >> chosenPlayerName;
                    needToPickANewName = false;
                }
                if (chosenPlayerName == players[j].getName())
                {
                    needToPickANewName = true;
                }
            }
            allNamesChecked = true;
        }

        Player tempPlayer = players[i];
        tempPlayer.setName(chosenPlayerName);
        players[i] = tempPlayer;
    }
    cout << "\nPlayer names set. \n" << endl;
}

// Returns a random number between 1 and 6, with some flavor text.
int GameMaster::spinTheWheel()
{
    int number = rand() % 6;
    cout << "You rolled: " << number << endl;
    return number;
}

// Prompts the user to choose a path, then returns a modified Player copy with the chosen path
Player GameMaster::chooseAPath(Player player)
{
    int choice;
    cout << "Do you wish to train before you head to the Promise Land? (1 for yes, 0 for no): " << endl;
    cin >> choice;
    if (choice == 0)
    {
        cout << "You head straight to the Promise Land: " << endl;
        player.toPrideLand();
    }
    else if (choice == 1)
    {
        cout << "You decided to train before embarking: " << endl;
        player.trainCub(2000, 2000, 1000);
    }

    return player;
}

// // Prints out a menu with all the players and their stats
// void GameMaster::mainMenu(Player players[], const int PLAYERS_SIZE)
// {

// }
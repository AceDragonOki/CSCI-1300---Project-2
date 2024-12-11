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

// Reads a txt file and parses it into a passed-in 2D array. Note that the passed-in array must have width 10, and that fileName should include the file extension (e.g. "character.txt"). Array size of 10 was chosen arbitrarily, but should fit all cases.
void GameMaster::parseFileInto2DArray(string arr[][10], string fileName, const int NUM_ARRAY_ITEMS)
{
    ifstream file(fileName);
    if (!file.is_open())
    {
        cout << "Could not open file." << endl;
        return;
    }

    string currentLine;
    int lineIndex = 0;
    bool firstLineSkipped = false;

    while (getline(file, currentLine))
    {
        if (!firstLineSkipped)
        { // skips header
            firstLineSkipped = true;
            continue;
        }
        string thisLinesArray[10];
        split(currentLine, '|', thisLinesArray, 10);

        // copying the values of thisLinesArray into the elements of arr[][]
        for (int i = 0; i < NUM_ARRAY_ITEMS; i++)
        {
            arr[lineIndex][i] = thisLinesArray[i];
        }
        lineIndex++;
    }
}

// Prompts the user to pick a character from the available characters in character.txt. Also asks the player if they would like to train, ensures the character they choose is not picked by any other players, and assigns the player an ID (playerNumber).
void GameMaster::characterCreation(Player players[], const int NUM_PLAYERS, string advisors[][10], const int NUM_ADVISORS)
{

    string chosenPlayerName;
    for (int i = 0; i < NUM_PLAYERS; i++)
    {

        cout << "Player " << i + 1 << ": Write your character's name:" << endl;
        cin >> chosenPlayerName;

        bool allNamesChecked = false;
        bool needToPickANewName = false;

        while (!allNamesChecked)
        {
            for (int j = 0; j < NUM_PLAYERS; j++)
            {
                if (needToPickANewName)
                {
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

        int age = pickAnAge();

        const int NUMBER_OF_BUILDS = 4; // adjust this if number of builds ever changes
        string builds[NUMBER_OF_BUILDS][10];

        parseFileInto2DArray(builds, "builds.txt", NUMBER_OF_BUILDS);

        string build = pickABuild(builds, NUMBER_OF_BUILDS);

        int str = -1;
        int sta = -1;
        int wis = -1;
        int pridePoints = 2000;

        for (int i = 0; i < NUMBER_OF_BUILDS; i++){
            if (build == builds[i][0]){
                str = stoi(builds[i][1]);
                sta = stoi(builds[i][2]);
                wis = stoi(builds[i][3]);
            }
        }

        Player newPlayer = Player(chosenPlayerName, str, sta, wis, age, pridePoints);
        players[i] = newPlayer;

        string trainingConfirm = "";
        cout << "Would you like to train your cub? (+200 STR, STA, and WIS). Also places you on the second track.) \nType 'TRAIN' if you would like to train, or anything else to decline. Should you decline, you will gain 3000 Pride Points, for bravery." << endl;
        cin >> trainingConfirm;
        if (trainingConfirm == "TRAIN")
        {
            players[i].trainCub(200, 200, 200, advisors, NUM_ADVISORS);
        } else {
            players[i].setPridePoints(3000); //add 3000 pride points for taking it risky
        }
    }
    cout << "\nPlayers created. \n"
         << endl;
}

// Prompts the user to select an age for their character.
int GameMaster::pickAnAge()
{
    int age = -1;
    string proposedAge = "";
    cout << "Please type in your character's age: " << endl;
    cin >> proposedAge;
    while (true)
    {
        if (validateInt(proposedAge) && stoi(proposedAge) > 0)
        {
            age = stoi(proposedAge);
            break;
        }
        cout << "That is not a valid age. Please input a non-negative integer." << endl;
        cin >> proposedAge;
    }

    return age;
}

// Happens during character creation. Reads from builds array and prints out the options, then has the player select the option they want. Returns the name of the build they choose.
string GameMaster::pickABuild(string builds[][10], const int NUMBER_OF_BUILDS)
{
    string playerInput;
    cout << "Please select a build for your cub. Your options are: ";
    for (int i = 0; i < NUMBER_OF_BUILDS; i++)
    {
        if (i == NUMBER_OF_BUILDS - 1)
        {
            cout << "or " << builds[i][0];
        }
        else
        {
            cout << builds[i][0] << ", ";
        }
    }
    cout << endl;
    cin >> playerInput;

    bool properBuildFound = false;

    while (true)
    {
        for (int i = 0; i < NUMBER_OF_BUILDS; i++)
        {
            if (playerInput == builds[i][0])
            {
                properBuildFound = true;
            }
        }
        if (properBuildFound){
            break;
        }
        cout << "That build does not exist. Please select a build from the list. Ensure selections are made with proper capitalization." << endl;
        cin >> playerInput;
    }

    cout << "Build selected: " << playerInput << endl;
    return playerInput;
}

// Returns a random number between 1 and 6, with some flavor text.
int GameMaster::spinTheWheel()
{
    int number = (rand() % 6)+1;
    cout << "You rolled: " << number << "." << endl;
    return number;
}


// // See pickAdvisor in Player.cpp
// Player GameMaster::selectAdvisor(int playerNumber, Player players[], int NUM_PLAYERS){
//     string choice;
//     bool canBeChosen = false;
//     while(!canBeChosen){
//         cout << "Which advisor do you wish to seek assistance from:\n(Options are: Rafiki, Nala, Sarabi, Zazu, Sarafina) " << endl;
//         cin >> choice;

//         if(choice == players[playerNumber].getAdvisor()){
//             cout << "You have decided to stick with " << choice << " as your advisor." << endl;
//         }
        
//         if(choice == "Rafiki" || choice == "Nala" || choice == "Sarabi" || choice == "Zazu" || choice == "Sarafina"){
//             canBeChosen = true;
//             for(int i = 0; i < NUM_PLAYERS; i++){
//                 if(choice == players[i].getAdvisor()){
//                     cout << choice << " is already advising " << players[i].getName() << "." << endl;
//                     canBeChosen = false;
//                 }
//             }
//         } else {
//             cout << choice << " is not a valid option." << endl;
//         }
//     }

//     cout << choice << " is your new advisor!" << endl;
//     players[playerNumber].setAdvisor(choice);

//     return players[playerNumber];

// }

// // Prompts the user to choose a path, then returns a modified Player copy with the chosen path
// Player GameMaster::chooseAPath(Player player)
// {
//     int choice;
//     cout << "Do you wish to train before you head to the Promise Land? (1 for yes, 0 for no): " << endl;
//     cin >> choice;
//     if (choice == 0)
//     {
//         cout << "You head straight to the Promise Land: " << endl;
//         player.toPrideLand();
//     }
//     else if (choice == 1)
//     {
//         cout << "You decided to train before embarking: " << endl;
//         player.trainCub(2000, 2000, 1000);
//     }

//     return player;
// }

// // Prints out a menu with all the players and their stats
// void GameMaster::mainMenu(Player players[], const int NUM_PLAYERS)
// {

// }

// // Writes endgame data to a file
// void GameMaster::writeGameDataToFile(Player players[], const int NUM_PLAYERS){
// TODO: decide what to write to a file here, and impliment it. Maybe just endgame stats and who won?
// }

// Prompts the users to select the number of players in the game. Returns the number of players selected. Also whoops, numPlayers needs to be a const, so this might actually all be useless.
int GameMaster::decideNumPlayers()
{
    string proposedNumPlayers = "";
    cout << "How many players would you like to have?" << endl;
    cin >> proposedNumPlayers;

    bool validNumPlayersInputted = false;
    int numPlayers = -1;

    while (!validNumPlayersInputted)
    {
        if (validateInt(proposedNumPlayers) && stoi(proposedNumPlayers) > 1)
        {
            numPlayers = stoi(proposedNumPlayers);
            validNumPlayersInputted = true;
        }
        else
        {
            cout << "Invalid number of players requested. Please input an integer between 2 and 10, inclusive." << endl;
            cin >> proposedNumPlayers;
        }
    }
    return numPlayers;
}

int GameMaster::evaluateScore(Player player){
    int total = 0;
    total += player.getPridePoints();
    total += (player.getStamina()/100)*1000;
    total += (player.getWisdom()/100)*1000;
    total += (player.getStrength()/100)*1000;
    return total;
}



Player GameMaster::playerTurn(int playerNumber, Board board, Player players[], int NUM_PLAYERS, string events[][10], const int NUM_EVENTS, string riddles[][10], const int NUM_RIDDLES, string advisors[][10], const int NUM_ADVISORS){//feel free to add more actions during a turn
    cout << players[playerNumber].getName() << ", it's your turn! What would you like to do?\n1. Board Info\n2. Player Info\n3. Move (Warning: This action ends your turn)" << endl;
    int choice;
    cin >> choice;
    while(choice != 3){
        if(choice == 1){ // might remove board info since you need the player array and number of player info as well.
            board.displayBoard(players, NUM_PLAYERS);

        } else if(choice == 2){
            players[playerNumber].printStats();
        } else {
            cout << "That is not a valid choice."<< endl;
        } 
        cout << "What would you like to do?\n1. Board Info\n2. Player Info\n3. Move (Warning: This action ends your turn)" << endl;
        cin >> choice;
    }

    players[playerNumber] = movementAction(playerNumber, board, players, NUM_PLAYERS, events, NUM_EVENTS, riddles, NUM_RIDDLES, advisors, NUM_ADVISORS);
    return players[playerNumber];
}

Player GameMaster::movementAction(int playerNumber, Board board, Player players[], int NUM_PLAYERS,string events[][10], const int NUM_EVENTS, string riddles[][10], const int NUM_RIDDLES, string advisors[][10], const int NUM_ADVISORS){// TODO: still need to impliment Challenge Tile and Normal Tile
    int movement = spinTheWheel();

    players[playerNumber].movePosition(movement);

    //check for game end condition here later on

    int position = players[playerNumber].getPosition();
    int track = players[playerNumber].getTrained();
    Tile tile = board.getTile(track, position);

    board.displayBoard(players, NUM_PLAYERS);
    
    char color = tile.getColor();
    if(color == 'B'){ //oasis tile
        cout << "You've found a peaceful oasis! Take a deep breath and relax...\n(You gained 200 stamina)\n(You gained 200 strength)\n(You gained 200 wisdom)\n(You gained an extra turn)" << endl;
        players[playerNumber].setStamina(players[playerNumber].getStamina()+200);
        players[playerNumber].setStrength(players[playerNumber].getStrength()+200);
        players[playerNumber].setWisdom(players[playerNumber].getWisdom()+200);
        players[playerNumber] = playerTurn(playerNumber, board, players, NUM_PLAYERS, events, NUM_EVENTS, riddles, NUM_RIDDLES, advisors, NUM_ADVISORS); // recursion!!! Let's go!!!

    }else if(color == 'P'){ //Counsiling Tile
        cout << "Welcome to the land of enrichment -- \nWhen landing on this tile, your Stamina, Strength, and Wisdom Points increase by 300, and you get to choose an advisor from the available list of advisors. \nIf you already have an advisor, you can switch your advisor out for a different one from the list or keep your original advisor. \nDo not forget - an advisor can protect you from random events that negatively impact your Pride Points." << endl;
        players[playerNumber].setStamina(players[playerNumber].getStamina()+300);
        players[playerNumber].setStrength(players[playerNumber].getStrength()+300);
        players[playerNumber].setWisdom(players[playerNumber].getWisdom()+300);

        for (int i = 0; i < NUM_ADVISORS; i++){ // makes advisor available
            if (players[playerNumber].getAdvisor() == advisors[i][0]){
                advisors[i][2] = "Available";
            }
        }

        players[playerNumber].setAdvisor(players[playerNumber].pickAdvisor(advisors, NUM_ADVISORS)); // sets player's advisor to something new

    }else if(color == 'R'){ //Graveyard Tile
        cout << "Uh-oh, you've stumbled into the Graveyard!\n(You lose 100 stamina)\n(You lose 100 strength)\n(You lose 100 wisdom)\n(You move back 10 spaces)" << endl;
        players[playerNumber].setStamina(players[playerNumber].getStamina()-100);
        players[playerNumber].setStrength(players[playerNumber].getStrength()-100);
        players[playerNumber].setWisdom(players[playerNumber].getWisdom()-100);
        players[playerNumber].movePosition(-10);

        board.displayBoard(players, NUM_PLAYERS);

    }else if(color == 'U'){ //Challenge Tile

        cout << "Time for a test of wits! Answer correctly, and you'll earn a boost of 500 Points to your Wisdom Trait." << endl;
        int chosenRiddle = rand() % NUM_RIDDLES;
        string input;
        cout << riddles[chosenRiddle][0] << endl;
        cin >> input;

        if(input == riddles[chosenRiddle][1]){
            cout << "Your cleverness pays off! Your wisdom increases by 500" << endl;
            players[playerNumber].setWisdom(players[playerNumber].getWisdom()+500);
        } else {
            cout << "Sorry, you got it wrong." << endl;
        }

    }else if(color == 'N'){//Hyena Tile
        cout << "The Hyenas are on the prowl! They drag you back to where you were last, and the journey comes at a cost.\nYou lose 300 stamina\nYou move back to your original position" << endl;
        players[playerNumber].setStamina(players[playerNumber].getStamina()-300);
        players[playerNumber].movePosition(-movement);

        board.displayBoard(players, NUM_PLAYERS);

    }else{//Normal Tile
        //TODO: Make advisors relevant to quest items
        if(rand() % 2 == 0){
            int chosenEvent = rand() % NUM_EVENTS;
            cout << events[chosenEvent][0] << endl;
            players[playerNumber].setPridePoints(players[playerNumber].getPridePoints()+stoi(events[chosenEvent][3]));
        }
    }

    return players[playerNumber];
}

bool GameMaster::gameEndCondition(Player players[], int NUM_PLAYERS){
    for(int i = 0; i < NUM_PLAYERS; i++){
        if(players[i].getPosition() < 51){
            return false;
        }
    }

    return true;
}



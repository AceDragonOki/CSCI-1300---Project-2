//Worked on by: Alec Ebert, Alex Class

#include "Board.h"
#include "Player.h"
#include "Tile.h"
#include <iostream>

using namespace std;

bool validateInt(string number){
    
    for(int i = 0; i < number.length(); i++){
        
        if(number[i] == '-'){
            if(i != 0){
                return false;
            }
        } else if(!(int(number[i]) >= 48 && int(number[i]) <= 57)){
            return false;
        }

    }
    return true;
}

int split(string input_string, char separator, string arr[], const int ARR_SIZE){
    int starting = 0;
    int x = 0;
    for(int i = 0; i < int(input_string.length()); i++){
        if(input_string[i] == separator){
            if(x < ARR_SIZE){
                arr[x] = input_string.substr(starting,i-starting);
                starting = i+1;
                x++;
            } else {
                return -1;
            }
        }
        
    }
    if(x < ARR_SIZE){
        arr[x] = input_string.substr(starting,int(input_string.length())-starting);
        x++;
    } else {
        return -1;
    }
    return x;
}

string extractSpecificLine(){ //this function will extract a specific line from a file and return it as a string

}

Player promptForChosingCharacter(Player players[], const int PLAYERS_SIZE, int playerIndex){
    int chosenPlayer;
    for(int i = 0; i < PLAYERS_SIZE; i++){

        cout << "Player " << i+1 << "Choose your Character (1. Appolo : 2. Mane : 3. Elsa : 4. Zuri : 5. Roary)" << endl;
        cin >> chosenPlayer;

        for(int j = 0; j < i; j++){

        }


    }
    

    
} // Prompts the user to pick a character from the available characters in character.txt.
    // Also ensures the character they choose is not picked by any other players.

int spinTheWheel(){
    int number = rand()%6;
    cout << "You rolled: " << number << endl;
    return number;

} // returns a random value along with some print statements for flavor
Player chooseAPath(Player player){
    int choice;
    cout << "Do you wish to train before you head to the Promise Land? (1 for yes, 0 for no): " << endl;
    cin >> choice;
    if(choice == 0){
        cout << "You head straight to the Promise Land: " << endl;
        player.toPrideLand();
    } else if(choice == 1){
        cout << "You decided to train before embarking: " << endl;
        player.trainCub(2000,2000,1000);
    }

    return player;

} // Prompts the user to choose a path
void mainMenu(Player players[], const int PLAYERS_SIZE){

} // prints out a menu with all the players and their stats
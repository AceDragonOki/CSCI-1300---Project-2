//Worked on by: Alec Ebert, Alex Class

#include "Board.h"
#include "Player.h"
#include "Tile.h"
#include "GameMaster.h"
#include <iostream>

using namespace std;

int main(){
    GameMaster gm;

    const int NUM_PLAYERS = 2;

    Board board = Board(NUM_PLAYERS);
    Player players[NUM_PLAYERS]; 


    gm.characterCreation(players, NUM_PLAYERS);

    board.initializeBoard();
    board.displayBoard(players, NUM_PLAYERS);

    for (int i = 0; i < NUM_PLAYERS; i++){
        players[i].printStats();
    }
    
}
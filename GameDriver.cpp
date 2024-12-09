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

    srand(time(0)); //sets up the random numbers

    board.initializeBoard();
    board.displayBoard(players, NUM_PLAYERS);

    for (int i = 0; i < NUM_PLAYERS; i++){
        players[i].printStats();
    }
    //cout << gm.evaluateScore(players[0]) << endl;
    players[0] = gm.playerTurn(players[0], board);

    board.displayBoard(players, NUM_PLAYERS);
    
}

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

    const int NUM_ADVISORS = 7;
    string advisors[NUM_ADVISORS][10];
    gm.parseFileInto2DArray(advisors, "advisors.txt",NUM_ADVISORS);

    gm.characterCreation(players, NUM_PLAYERS, advisors, NUM_ADVISORS);

    const int NUM_EVENTS = 18;
    const int NUM_RIDDLES = 10;

    string events[NUM_EVENTS][10];
    string riddles[NUM_RIDDLES][10];

    gm.parseFileInto2DArray(events, "randomEvents.txt",NUM_EVENTS);
    gm.parseFileInto2DArray(riddles, "riddles.txt",NUM_RIDDLES);

    srand(time(0)); //sets up the random numbers

    board.initializeBoard();
    board.displayBoard(players, NUM_PLAYERS);

    for (int i = 0; i < NUM_PLAYERS; i++){
        players[i].printStats();
    }
    while(!gm.gameEndCondition(players, NUM_PLAYERS)){
        for(int i = 0; i < NUM_PLAYERS; i++){
            if(players[i].getPosition() < 51){
                players[i] = gm.playerTurn(i, board, players, NUM_PLAYERS, events, NUM_EVENTS, riddles, NUM_RIDDLES, advisors, NUM_ADVISORS);
            }
        }
    }
    gm.results(players, NUM_PLAYERS);
    

    //board.displayBoard(players, NUM_PLAYERS);
    
}

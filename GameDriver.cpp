#include "Board.h"
#include "Player.h"
#include "Tile.h"
#include <iostream>

using namespace std;

int main(){
    Player simba = Player("Simba", 200, 200, 200);
    simba.setAdvisor("Nala");
    simba.printStats();
    cout << simba.getTrained() << endl;

    Board test = Board(1);
    test.initializeBoard();
    test.displayBoard();



    
}
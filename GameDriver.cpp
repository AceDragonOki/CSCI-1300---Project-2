//Worked on by: Alec Ebert, Alex Class

#include "Board.h"
#include "Player.h"
#include "Tile.h"
#include "GameMaster.h"
#include <iostream>

using namespace std;

int main(){
    Player envy = Player("", 200, 200, 200);
    Player pride = Player("", 200, 200, 200);
    Player greed = Player("", 200, 200, 200);
    Player sloth = Player("", 200, 200, 200);

    Player players[] = {envy, pride, greed, sloth};

    GameMaster myGameMaster;

    myGameMaster.promptForChoosingCharacters(players, 4);

    players[0].printStats();
    players[1].printStats();
    players[2].printStats();
    players[3].printStats();
}
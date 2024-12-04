//Worked on by: Alec Ebert, Alex Class

#include "Board.h"
#include "Player.h"
#include "Tile.h"
#include "GameMaster.h"
#include <iostream>

using namespace std;

int main(){
    GameMaster myGM;

    string my2DArray[10][10];

    myGM.parseFileInto2DArray(my2DArray, "character.txt", 4);

    for (int row = 0; row < 5; row++){
        for (int col = 0; col < 6; col++){
            cout << my2DArray[row][col] << " ";;
        }
        cout << endl;
    }
    
}
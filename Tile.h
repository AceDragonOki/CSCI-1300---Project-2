//Worked on by: Alec Ebert, Alex Class

/* The Tile structure contains two variables, one for color and one for event.
 - Tile type varies based on the numeric value of event.
*/

#pragma once
class Tile{
    private:
        char color;
        int event;
    public: 
        Tile();
        Tile(char col, int eve);
        char getColor();
        void setColor(char col);
        int getEvent();
        void setEvent(int eve);
};

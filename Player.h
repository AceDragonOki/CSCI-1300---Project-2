//Worked on by: Alec Ebert, Alex Class

#pragma once

#include <string>

using namespace std;

class Player
{
private:
    string name;
    int strength;
    int stamina;
    int wisdom;
    int pridePoints;
    int age;
    string advisor;
    bool trained;
    int position;
public:
    Player ();
    Player(string n, int str, int sta, int wis, int a, int pp);
    int getStrength();
    void setStrength(int strength);
    int getStamina();
    void setStamina(int stamina);
    int getWisdom();
    void setWisdom(int wisdom);
    int getPridePoints();
    void setPridePoints(int pridePoints);
    int getAge();
    void setAge(int age);
    string getName();
    void setName(string n);
    string getAdvisor();
    void setAdvisor(string a);
    bool getTrained();
    void setTrained(bool t);
    int getPosition();
    void setPosition(int pos);
    

    void trainCub(int strength, int stamina, int wisdom);
    void toPrideLand();
    void printStats();
};
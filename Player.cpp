//Worked on by: Alec Ebert, Alex Class

#include "Player.h"
#include <iostream>
using namespace std;

Player::Player()
{
    name = "";

    stamina = 100;
    strength = 100;
    wisdom = 100;

    advisor = "";
    trained = 0;

    pridePoints = 0;
    age = 1;
    position = 0;
};

Player::Player(string n, int str, int sta, int wis, int a, int pp)
{
    name = n;

    pridePoints = pp;
    age = a;

    advisor = "";
    trained = 0;

    if (str >= 100 && str <= 1000)
    {
        strength = str;
    }
    else
    {
        strength = 100;
    }

    if (sta >= 100 && sta <= 1000)
    {
        stamina = sta;
    }
    else
    {
        stamina = 100;
    }

    if (wis >= 100 && wis <= 1000)
    {
        wisdom = wis;
    }
    else
    {
        wis = 100;
    }

    position = 0;
};

string Player::getName()
{
    return name;
}

int Player::getStamina()
{
    return stamina;
}

int Player::getStrength()
{
    return strength;
}

int Player::getWisdom()
{
    return wisdom;
}

int Player::getPridePoints()
{
    return pridePoints;
}

int Player::getAge()
{
    return age;
}

int Player::getTrained(){
    return trained;
}

string Player::getAdvisor(){
    return advisor;
}

int Player::getPosition(){
    return position;
}

void Player::setName(string n)
{
    name = n;
}

void Player::setStrength(int str)
{
    strength = str;
}

void Player::setStamina(int sta)
{
    stamina = sta;
}

void Player::setWisdom(int wis)
{
    wisdom = wis;
}

void Player::setPridePoints(int pride)
{
    pridePoints = pride;
}

void Player::setAge(int a)
{
    if (a >= 1 && a <= 20)
    {
        age = a;
    }
}

void Player::setPosition(int pos){
    if(pos < 0){
        cout << "Attempted to reach invalid position." << endl;
    }else if(pos > 51){
        position = 51;
    } else {
        position = pos;
    }
}

void Player::setAdvisor(string a){
    if (a != "Rafiki" && a != "Nala" && a != "Sarabi" && a != "Zazu" && a != "Sarafina"){
        advisor = "";
        cout << "Advisor not recognized." << endl;
    } else {
        advisor = a;
    }
    
}

void Player::setTrained(int t){
    trained = t;
}

void Player::trainCub(int str, int sta, int wis, string advisors[][10], const int NUM_ADVISORS)
{
    wisdom += wis;
    stamina += sta;
    strength += str;
    trained = 1;
    advisor = pickAdvisor(advisors, NUM_ADVISORS);
}

string Player::pickAdvisor(string advisors[][10], const int NUM_ADVISORS){
    cout << "Please select an advisor (write their number):" << endl;
    for (int i = 0; i < NUM_ADVISORS; i++){
        cout << i + 1 << ") " << advisors[i][0] << " (" << advisors[i][2] << ")" << endl;
    }

    string playerInput;
    int playerInputParsed = 0;
    string chosenAdvisor = "";

    while (true){
        cin >> playerInput;

        try { // code so bad they made me pull out the try catch block :sob:
            playerInputParsed = stoi(playerInput);
        } catch(...) {
            playerInputParsed = 0;
        }

        if (playerInputParsed > 0 && playerInputParsed <= NUM_ADVISORS && advisors[playerInputParsed - 1][2] == "Available"){
            chosenAdvisor = advisors[playerInputParsed - 1][0];
            advisors[playerInputParsed - 1][2] = "Taken";
            break;
        } else if (advisors[playerInputParsed - 1][2] == "Taken"){
            cout << "Please select an advisor that hasn't already been taken." << endl;
        } else {
            cout << "Please input a positive integer corresponding to an advisor." << endl;
        }
    }

    cout << "You have choosen " << chosenAdvisor << "!" << endl;

    return chosenAdvisor;
}

void Player::toPrideLand()
{
    pridePoints += 5000;
    wisdom -= 2000;
    strength -= 2000;
    stamina -= 1000;
}

void Player::printStats()
{
    cout << name << ", age " << age << endl;
    cout << "STR: " << strength << " | STA: " << wisdom << " | WIS: " << wisdom << endl;
    cout << "Pride Points: " << pridePoints << endl;
    cout << "Advisor: ";
    if (advisor == ""){
        cout << "None";
    } else {
        cout << advisor;
    }
    cout << endl;
    cout << "---------------------" << endl;
}

void Player::movePosition(int spaces){
    if(getPosition()+spaces < 0){
        setPosition(0);
    } else {
        setPosition(getPosition()+spaces);
    }
}

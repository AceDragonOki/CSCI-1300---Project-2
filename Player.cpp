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

void Player::trainCub(int str, int sta, int wis)
{
    wisdom += wis;
    stamina += sta;
    strength += str;
    pridePoints -= 5000;
    trained = 1;
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
    cout << "STR: " << strength << " | STA: " << wisdom << " | WIS: " << wisdom << endl;;
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
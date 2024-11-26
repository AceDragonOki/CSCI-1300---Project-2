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
    trained = false;

    pridePoints = 0;
    age = 1;
};

Player::Player(string n, int str, int sta, int wis)
{
    name = n;

    pridePoints = 0;
    age = 1;

    advisor = "";
    trained = false;

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

bool Player::getTrained(){
    return trained;
}

string Player::getAdvisor(){
    return advisor;
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

void Player::setAdvisor(string a){
    if (a != "Rafiki" && a != "Nala" && a != "Sarabi" && a != "Zazu" && a != "Sarafina"){
        advisor = "";
        cout << "Advisor not recognized." << endl;
    } else {
        advisor = a;
    }
    
}

void Player::setTrained(bool t){
    trained = t;
}

void Player::trainCub(int str, int sta, int wis)
{
    wisdom += wis;
    stamina += sta;
    strength += str;
    pridePoints -= 5000;
    trained = true;
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
    cout << "Strength: " << strength << endl;
    cout << "Stamina: " << stamina << endl;
    cout << "Wisdom: " << wisdom << endl;
    cout << "Pride Points: " << pridePoints << endl;
    cout << "Advisor: " << advisor << endl;
}
#include <iostream>
#include <iomanip>
using namespace std;

class Player{
    private:
    string name;
    int strength, stamina, wisdom, pridePoints, age;

    public:
    Player(){
        name = "";

        stamina = 100;
        strength = 100;
        wisdom = 100;

        pridePoints = 0;
        age = 1;
    };

    Player(string n, int str, int sta, int wis){
        name = n;

        pridePoints = 0;
        age = 1;

        if(str >= 100 && str <= 1000){
            strength = str;
        } else {
            strength = 100;
        }

        if(sta >= 100 && sta <= 1000){
            stamina = sta;
        } else {
            stamina = 100;
        }

        if(wis >= 100 && wis <= 1000){
            wisdom = wis;
        } else {
            wis = 100;
        }
        
    };

    string getName(){
        return name;
    }

    int getStamina(){
        return stamina;
    }

    int getStrength(){
        return strength;
    }

    int getWisdom(){
        return wisdom;
    }

    int getPridePoints(){
        return pridePoints;
    }

    int getAge(){
        return age;
    }

    void setName(string n){
        name = n;
    }

    void setStrength(int str){
        strength = str;
    }

    void setStamina(int sta){
        stamina = sta;
    }

    void setWisdom(int wis){
        wisdom = wis;
    }

    void setPridePoints(int pride){
        pridePoints = pride;
    }

    void setAge(int a){
        if(a >= 1 && a <= 20){
            age = a;
        }
    }

    void trainCub(int str, int sta, int wis){
        wisdom += wis;
        stamina += sta;
        strength += str;
        pridePoints -= 5000;

    }

    void toPrideLand(){
        pridePoints += 5000;
        wisdom -= 2000;
        strength -= 2000;
        stamina -= 1000;
    }

    void printStats(){
        cout << name << ", age " << age << endl;
        cout << "Strength: " << strength << endl;
        cout << "Stamina: " << stamina << endl;
        cout << "Wisdom: " << wisdom << endl;
        cout << "Pride Points: " << pridePoints << endl;
    }

};
#include <iostream>
#include <fstream> 
#include "player.h"

using namespace std;

players::players(){
    _Name = "";
    _Strength = 100;
    _Stamina = 100;
    _Wisdom = 100;
    _Pride_points = 0;
    _Age = 1;
    boardOptions = 0;

}

//ifstream in_file;
//in_file.open("character.txt")



players::players(string name, int strength, int stamina, int wisdom){
    _Name = name;
    
    if(strength > 1000 || strength < 100){
        _Strength = 100;
    }
    else{
        _Strength = strength;
    }

    if(stamina > 1000 || stamina < 100){
        _Stamina = 100;
    }
    else{
        _Stamina = stamina;
    }

    if(wisdom > 1000 || wisdom < 100){
        _Wisdom = 100;
    }
    else{
        _Wisdom = wisdom;
    };


}

string players::getName(){
    return _Name;

}

int players::getStrength() const{
    return _Strength;
}

int players::getStamina() const{
    return _Stamina;
}

int players::getWisdom() const{
    return _Wisdom;
}

int players::getPridePoints() const{
    return _Pride_points;
}

int players::getAge() const{
    return _Age;
}

void players::setName(string name){
    _Name = name;
}
void players::setStrength(int strength){
    _Strength = strength;
}
void players::setStamina(int stamina){
    _Stamina = stamina;
}

void players::setWisdom(int wisdom){
    _Wisdom = wisdom;
}

void players::setPridePoints(int pride_points){
    _Pride_points = pride_points;
}

void players::setAge(int age){
    _Age = age;
}

void players::addStrength(int strength){
    _Strength += strength;
}

void players::addStamina(int stamina){
    _Stamina += stamina;
}

void players::addWisdom(int wisdom){
    _Wisdom += wisdom;
}

void players::addPridePoints(int pride_points){
    _Pride_points += pride_points;
}

void players::addAge(int age){
    _Age += age;
}

void players::trainCub(int strength, int stamina, int wisdom){
    _Strength += strength;
    _Stamina += stamina;
    _Wisdom += wisdom;
    _Pride_points -= 5000;
}

void players::toPrideLands(){
    _Pride_points += 5000;
    _Strength -= 2000;
    _Wisdom -= 2000;
    _Stamina -= 1000;

}

void players::printStats(){
    cout << _Name << ", " << _Age << endl;
    cout << "Strength: " << _Strength << endl;
    cout << "Stamina: " << _Stamina << endl;
    cout << "Wisdom: " << _Wisdom << endl;
    cout << "Pride Points: " << _Pride_points << endl;


}

int players::getboardOptions(){
    return boardOptions;
}

void players::setboardOptions(int board){
    boardOptions = board;
}

void players::setAdvisor()
{

}






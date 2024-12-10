#include <iostream>
using namespace std;


#ifndef PLAYER_h
#define PLAYER_h

//change theme
class players{
    public:
    players();
    players(string name, int strength, int stamina, int wisdom);
    string getName();
    int getStrength() const;
    int getStamina() const;
    int getWisdom() const;
    int getPridePoints() const;
    int getAge() const;
    void setName(string name);
    void setStrength(int strength);
    void setStamina(int stamina);
    void setWisdom(int wisdom);
    void setPridePoints(int pride_points);
    void setAge(int age);
    void addStrength(int strength);
    void addStamina(int stamina);
    void addWisdom(int wisdom);
    void addPridePoints(int pride_points);
    void addAge(int age);
    void trainCub(int strength, int stamina, int wisdom);
    void toPrideLands();
    void printStats();
    int getboardIndex();
    int getboardOptions();
    void setboardOptions(int board);
    int getAdvisorChoice(); 
    void setAdvisor();
    int getboardc();
    void trainCub();
    int player();
    
    
  
    int play;

    
    private:
    string _Name;
    int _Strength;
    int _Stamina;
    int _Wisdom;
    int _Pride_points;
    int _Age;
    int boardOptions;
    
    

};

#endif
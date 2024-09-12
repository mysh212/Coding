

#ifndef BATTLE_H
#define BATTLE_H
#include"Character.h"
// #include"../all.h"



class Battle {
    private:
    Character* f;
    
    public:
        Battle(int,int,Character*[]);
        static vector<Character> autm(int x);
        static vector<Character> autp(int x);
        bool battle(int,int,vector<Character>&);
};







#include"Battle.cpp"
#endif
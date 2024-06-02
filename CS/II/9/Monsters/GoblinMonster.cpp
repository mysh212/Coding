// Author : ysh
// 2024/04/24 Wed 19:19:26


#ifndef GoblinMonster_hR
#define GoblinMonster_hR

#include<string.h>
using namespace std;
#include"GoblinMonster.h"

GoblinMonster::GoblinMonster(string x):
    BaseMonster("Goblin",60,40,12,30,100,50) {};

    
GoblinMonster::GoblinMonster(string name,int attack,int defense,int exp,int money,int max_hp,int max_mp):
    BaseMonster(name,attack,defense,exp,money,max_hp,max_mp) {};


string GoblinMonster::serialize() {
    stringstream ss;
    ss << getHp() << "," << getMp() << "," << name << "," << exp << "," << money << "," << attack << "," << defense << "," << maxhp << "," << maxmp;
    string ans,pre;
    while(ss >> pre) ans = ans + pre;
    return ans;
}

GoblinMonster* GoblinMonster::unserialize(string x) {
    auto f = BaseMonster::split(x,",");
    GoblinMonster* ans = new GoblinMonster(f.at(2),stoi(f.at(5)),stoi(f.at(6)),stoi(f.at(3)),stoi(f.at(4)),stoi(f.at(7)),stoi(f.at(8)));
    ans->setHp(stoi(f.at(0)));
    ans->setMp(stoi(f.at(1)));
    return ans;
}

#endif
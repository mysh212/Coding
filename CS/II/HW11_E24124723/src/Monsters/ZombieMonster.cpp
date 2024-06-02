// Author : ysh
// 2024/04/24 Wed 19:19:26


#ifndef ZombieMonster_hR
#define ZombieMonster_hR

#include<string.h>
using namespace std;
#include"ZombieMonster.h"

ZombieMonster::ZombieMonster(string x):
    BaseMonster("Zombie",5,65,17,65,150,30) {};

    
ZombieMonster::ZombieMonster(string name,int attack,int defense,int exp,int money,int max_hp,int max_mp):
    BaseMonster(name,attack,defense,exp,money,max_hp,max_mp) {};


string ZombieMonster::serialize() {
    stringstream ss;
    ss << getHp() << "," << getMp() << "," << name << "," << exp << "," << money << "," << attack << "," << defense << "," << maxhp << "," << maxmp;
    string ans,pre;
    while(ss >> pre) ans = ans + pre;
    return ans;
}

ZombieMonster* ZombieMonster::unserialize(string x) {
    auto f = BaseMonster::split(x,",");
    ZombieMonster* ans = new ZombieMonster(f.at(2),stoi(f.at(5)),stoi(f.at(6)),stoi(f.at(3)),stoi(f.at(4)),stoi(f.at(7)),stoi(f.at(8)));
    ans->setHp(stoi(f.at(0)));
    ans->setMp(stoi(f.at(1)));
    return ans;
}

#endif
// Author : ysh
// 2024/04/24 Wed 19:19:25
#ifndef BaseMonster_hR
#define BaseMonster_hR

#include"BaseMonster.h"

BaseMonster::BaseMonster():
    hp(0), mp(0), name("Monster"), exp(0), money(0), attack(0), defense(0), maxhp(0), maxmp(0) {count++;};

BaseMonster::BaseMonster(const BaseMonster& a):
    exp(a.exp), money(a.money), attack(a.attack), defense(a.defense), maxhp(a.maxhp), maxmp(a.maxmp), name(a.name) {
    this->hp = a.hp;
    this->hp = a.hp;
    this->mp = a.mp;
    count++;
}

BaseMonster::BaseMonster(string name,int attack,int defense,int exp,int money,int max_hp,int max_mp):
    hp(max_hp), mp(max_mp), name(name), exp(exp), money(money), attack(attack), defense(defense), maxhp(max_hp), maxmp(max_mp) {count++;};

void BaseMonster::setHp(int x) {
    if(x < 0 || x > maxhp) return;
    hp = x;
    return;
}

void BaseMonster::setMp(int x) {
    if(x < 0 || x > maxmp) return;
    mp = x;
    return;
}

int BaseMonster::getHp() const {
    return hp;
}

int BaseMonster::getMp() const {
    return mp;
}

vector<string> BaseMonster::split(string a,string x) {
    vector<string>ans;
    string now = "";
    while(a.find(x) != string::npos) (a.find(x) == 0 ? void() : ans.push_back(a.substr(0,a.find(x)))),a = a.substr(a.find(x) + x.size());
    if(a != "") ans.push_back(a);
    return ans;
}

BaseMonster::~BaseMonster() {
    count--;
}

int BaseMonster::count = 0;

#endif
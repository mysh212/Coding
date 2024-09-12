// Author : ysh
// 2024/04/07 Sun 12:23:21
// #include<bits/stdc++.h>
// using namespace std;
// private:
//     string name;
//     int hp;
//     int mp;
//     int exp;
//     int money;
// protected:
//     int level;
//     int attack;
//     int defense;
//     int maxhp;
//     int maxmp;
//     int lvupexp;
// public:
#include"NovicePlayer.h"
    NovicePlayer::NovicePlayer():
        name("anonymous"), hp(0), mp(0), exp(0), money(0), level(1), attack(0), defense(0), maxhp(0), maxmp(0), lvupexp(0) {
            setLevel(1);
        };
    NovicePlayer::NovicePlayer(int a):
        NovicePlayer() {
            level = a;
            setLevel(a);
        };
    NovicePlayer::NovicePlayer(int a, string x):
        NovicePlayer(a) {
            name = x;
        };
    NovicePlayer::NovicePlayer(const NovicePlayer& a) {
        this->name = a.name;
        this->hp = a.hp;
        this->mp = a.mp;
        this->exp = a.exp;
        this->money = a.money;
        this->level = a.level;
        this->attack = a.attack;
        this->defense = a.defense;
        this->maxhp = a.maxhp;
        this->maxmp = a.maxmp;
        this->lvupexp = a.lvupexp;
        return;
    }
    
    void NovicePlayer::setName(string a) {
        name = a;
    }
    string NovicePlayer::getName() const {
        return name;
    }

    void NovicePlayer::preLevel(int a) {
        level = a;
        level = max(0,level);
        lvupexp = int(pow(10,log2(getLevel() + 1)) + 1);
    }

    void NovicePlayer::setLevel(int a) {
        maxhp = ct[0] + tz[0] * getLevel();
        maxmp = ct[1] + tz[1] * getLevel();
        attack = ct[2] + tz[2] * getLevel();
        defense = ct[3] + tz[3] * getLevel();

        setHp(getMaxHP());
        setMp(getMaxMP());
        return;
    }
    int NovicePlayer::getLevel() const {
        return level;
    }

    void NovicePlayer::setHp(int a) {
        hp = a;
        hp = max(0,min(hp,maxhp));
    }
    int NovicePlayer::getHp() const {
        return hp;
    }

    void NovicePlayer::setMp(int a) {
        mp = a;
        mp = max(0,min(hp,maxmp));
    }
    int NovicePlayer::getMp() const {
        return mp;
    }

    void NovicePlayer::setExp(int a) {
        this->exp = a;
        this->exp = max(0,this->exp);
    }
    int NovicePlayer::getExp() const {
        return exp;
    }

    void NovicePlayer::setMoney(int a) {
        money = a;
        money = max(0,money);
    }
    int NovicePlayer::getMoney() const {
        return money;
    }

    int NovicePlayer::getAttack() const {
        return attack;
    }
    int NovicePlayer::getDefense() const {
        return defense;
    }
    int NovicePlayer::getMaxHP() const {
        return maxhp;
    }
    int NovicePlayer::getMaxMP() const {
        return maxmp;
    }
    int NovicePlayer::getLvupExp() const {
        return lvupexp;
    }

    void NovicePlayer::upgrade() {
        level = level + 1;
    }

    

    vector<string> NovicePlayer::split(string a,string x) {
        vector<string>ans;
        string now = "";
        while(a.find(x) != string::npos) (a.find(x) == 0 ? void() : ans.push_back(a.substr(0,a.find(x)))),a = a.substr(a.find(x) + x.size());
        if(a != "") ans.push_back(a);
        return ans;
    }

    string NovicePlayer::serialize() {
        stringstream ss;
        ss << getHp() << "," << getMp() << "," << getName() << "," << getExp() << "," << getMoney() << "," << getAttack() << "," << getDefense() << "," << getMaxHP() << "," << getMaxMP() << "," << getLevel() << "," << getLvupExp();
        string ans,pre;
        while(ss >> pre) ans = ans + pre;
        return ans;
    }

    NovicePlayer* NovicePlayer::unserialize(string x) {
        auto f = split(x,",");
        NovicePlayer* ans = new NovicePlayer();
        
        ans->setHp(       stoi(     f.at(0)   )   );
        ans->setMp(       stoi(     f.at(1)   )   );
        ans->setName(               f.at(2)       );
        ans->setExp(      stoi(     f.at(3)   )   );
        ans->setMoney(    stoi(     f.at(4)   )   );
        ans->setAttack(   stoi(     f.at(5)   )   );
        ans->setDefense(  stoi(     f.at(6)   )   );
        ans->setMaxHP(    stoi(     f.at(7)   )   );
        ans->setMaxMP(    stoi(     f.at(8)   )   );
        ans->setLevel(    stoi(     f.at(9)   )   );
        return ans;
    }

    void NovicePlayer::setAttack(int x) {
        attack = x;
        return;
    }

    void NovicePlayer::setDefense(int x) {
        defense = x;
        return;
    }

    void NovicePlayer::setMaxHP(int x) {
        maxhp = x;
        return;
    }

    void NovicePlayer::setMaxMP(int x) {
        maxmp = x;
        return;
    }

    void NovicePlayer::setLvupExp(int x) {
        lvupexp = x;
        return;
    }
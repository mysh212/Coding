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
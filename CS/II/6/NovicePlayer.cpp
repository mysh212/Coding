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
    NovicePlayer::NovicePlayer():
        name("anonymous"), hp(0), mp(0), exp(0), money(0), level(1), attack(0), defense(0), maxhp(0), maxmp(0), lvupexp(0) {};
    NovicePlayer::NovicePlayer(int a):
        NovicePlayer() {
            level = a;
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
    string NovicePlayer::getName() const{
        return name;
    }

    void NovicePlayer::setLevel(int a) {
        level = a;
    }
    int NovicePlayer::getLevel() const {
        return level;
    }

    void NovicePlayer::setHp(int a) {
        hp = a;
    }
    int NovicePlayer::getHp() const {
        return hp;
    }

    void NovicePlayer::setMp(int a) {
        mp = a;
    }
    int NovicePlayer::getMp() const {
        return mp;
    }

    void NovicePlayer::setExp(int a) {
        this->exp = a;
    }
    int NovicePlayer::getExp() const {
        return exp;
    }

    void NovicePlayer::setMoney(int a) {
        money = a;
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

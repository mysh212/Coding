#ifndef NOVICEPLAYER_H
#define NOVICEPLAYER_H
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

class NovicePlayer
{
private:
	string name;
	int hp;
	int mp;
	int exp;
	int money;
protected:
	int level;
	int attack;
	int defense;
	int maxhp;
	int maxmp;
	int lvupexp;
public:
	NovicePlayer();
	NovicePlayer(int);
	NovicePlayer(int, string);
	NovicePlayer(const NovicePlayer&);
	
	void setName(string);
	string getName()const;

	void setLevel(int);
	int getLevel()const;

	void setHp(int);
	int getHp()const;

	void setMp(int);
	int getMp()const;

	void setExp(int);
	int getExp()const;

	void setMoney(int);
	int getMoney() const;

	int getAttack() const;
	int getDefense() const;
    int getMaxHP() const;
	int getMaxMP() const;
	int getLvupExp() const;

	void print() {
		cout << "-------------------------" << endl;
		cout << setw(10) << "name:" << getName() << endl;
		cout << setw(10) << "hp:" << getHp() << endl;
		cout << setw(10) << "mp:" << getMp() << endl;
		cout << setw(10) << "exp:" << getExp() << endl;
		cout << setw(10) << "money:" << getMoney() << endl;
		cout << setw(10) << "level:" << getLevel() << endl;
		cout << setw(10) << "attack:" << getAttack() << endl;
		cout << setw(10) << "defense:" << getDefense() << endl;
		cout << setw(10) << "maxhp:" << getMaxHP() << endl;
		cout << setw(10) << "maxmp:" << getMaxMP() << endl;
		cout << setw(10) << "lvup_exp:" << getLvupExp() << endl;
		cout << "-------------------------" << endl;
	}
};
#endif
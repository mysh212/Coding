#ifndef NOVICEPLAYER_H
#define NOVICEPLAYER_H
// #include <iomanip>
// #include <iostream>
// #include <string>
// using namespace std;

class NovicePlayer
{
private:
	static constexpr int ct[] = {100,40,20,20};
	static constexpr int tz[] = {10,5,5,5};
	string name;
	int hp;
	int mp;
	int exp;
protected:
	int money;
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

	void preLevel(int);
	virtual void setLevel(int);
	virtual void specialSkill() {};
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
	void setAttack(int);
	int getDefense() const;
	void setDefense(int);
    int getMaxHP() const;
	void setMaxHP(int);
	int getMaxMP() const;
	void setMaxMP(int);
	int getLvupExp() const;
	void setLvupExp(int);
	void upgrade();

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


	static vector<string> split(string,string);
	virtual string serialize();
	static NovicePlayer* unserialize(string);
};
#endif
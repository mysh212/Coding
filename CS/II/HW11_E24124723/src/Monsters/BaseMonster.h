
#include<string.h>
using namespace std;

#ifndef BaseMonster_h
#define BaseMonster_h

class BaseMonster
{
private:
	int hp;
	int mp;
public:
	const string name;
	const int exp;
	static int count;
	const int attack;
	const int defense;
	const int maxhp;
	const int maxmp;
	const int money;
	BaseMonster();
	BaseMonster(string,int,int,int,int,int,int);
	BaseMonster(const BaseMonster&);

	~BaseMonster();

	void setHp(int);
	int getHp()const;

	void setMp(int);
	int getMp()const;

	virtual string serialize() = 0;
	static vector<string> split(string,string);
	// static virtual BaseMonster* unserialize(string) = 0;
	friend ostream& operator<<(ostream& os,BaseMonster& monster) {
		os << "name:    " << monster.name << endl;
		os << "attack:  " << monster.attack << endl;
		os << "defense: " << monster.defense << endl;
		os << "hp:      " << monster.getHp() << " / " << monster.maxhp << endl;
		os << "mp:      " << monster.getMp() << " / " << monster.maxhp << endl;
		os << "exp:     " << monster.exp << endl;
		os << "money:   " << monster.money << endl;
		return os;
	}
	static int getInstanceCount() {
		return BaseMonster::count;
	}
};

#endif
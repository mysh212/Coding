
#include<string.h>
using namespace std;

#ifndef BaseMonster_h
#define BaseMonster_h

class BaseMonster
{
private:
	int hp;
	int mp;
protected:
	const string name;
	const int exp;
	const int money;
	static int count;
	const int attack;
	const int defense;
	const int maxhp;
	const int maxmp;
public:
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
	friend ostream& operator<<(ostream&,BaseMonster&);
	static int getInstanceCount() {
		return BaseMonster::count;
	}
};

#endif
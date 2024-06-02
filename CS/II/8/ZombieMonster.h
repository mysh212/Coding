
#ifndef ZombieMonster_h
#define ZombieMonster_h
#include"BaseMonster.cpp"
#include<string.h>
using namespace std;

class ZombieMonster: public BaseMonster
{
    public:
    ZombieMonster(string x = "123");
	ZombieMonster(string,int,int,int,int,int,int);
	string serialize();
	static ZombieMonster* unserialize(string);
};

#endif

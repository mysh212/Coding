
#ifndef GoblinMonster_h
#define GoblinMonster_h
#include"BaseMonster.cpp"
#include<string.h>
using namespace std;

class GoblinMonster: public BaseMonster
{
    public:
    GoblinMonster(string x = "123");
	GoblinMonster(string,int,int,int,int,int,int);
	string serialize();
	static GoblinMonster* unserialize(string);
};

#endif


#ifndef JWMonster_h
#define JWMonster_h
#include"BaseMonster.cpp"
#include<string.h>
using namespace std;

class JWMonster: public BaseMonster
{
    public:
    JWMonster(string x = "123");
	JWMonster(string,int,int,int,int,int,int);
	string serialize();
	pair<char,string> dump();
	static JWMonster* unserialize(string);
};

#endif

#ifndef KNIGHTPLAYER_H
#define KNIGHTPLAYER_H
#include"NovicePlayer.h"

class KnightPlayer :public NovicePlayer
{
	private:
	static constexpr int ct[] = {150,70,40,20};
	static constexpr int tz[] = {25,10,10,2};
	
	public:
	KnightPlayer();
	KnightPlayer(int);
	KnightPlayer(int, string);
	KnightPlayer(const KnightPlayer&);
	char get();
	void setLevel(int);
	void specialSkill();
	static KnightPlayer* unserialize(string);
};
#endif

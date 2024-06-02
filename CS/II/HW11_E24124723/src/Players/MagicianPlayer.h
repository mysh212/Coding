#ifndef MAGICIANPLAYER_H
#define MAGICIANPLAYER_H
#include"NovicePlayer.h"

class MagicianPlayer :public NovicePlayer
{
	private:
	static constexpr int ct[] = {120,100,30,20};
	static constexpr int tz[] = {15,15,8,7};

	public:
	MagicianPlayer();
	MagicianPlayer(int);
	MagicianPlayer(int, string);
	MagicianPlayer(const MagicianPlayer&);
	void setLevel(int);
	void specialSkill();
	static MagicianPlayer* unserialize(string);
};
#endif
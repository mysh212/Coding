#ifndef MAGICIANPLAYER_H
#define MAGICIANPLAYER_H
#include"NovicePlayer.h"

class MagicianPlayer :public NovicePlayer
{
public:
	MagicianPlayer();
	MagicianPlayer(int);
	MagicianPlayer(int, string);
	MagicianPlayer(const MagicianPlayer&);
	void setLevel(int);
	void pray();
};
#endif
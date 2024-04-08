#ifndef KNIGHTPLAYER_H
#define KNIGHTPLAYER_H
#include"NovicePlayer.h"

class KnightPlayer :public NovicePlayer
{
public:
	KnightPlayer();
	KnightPlayer(int);
	KnightPlayer(int, string);
	KnightPlayer(const KnightPlayer&);
	void setLevel(int);
	void heal();
};
#endif

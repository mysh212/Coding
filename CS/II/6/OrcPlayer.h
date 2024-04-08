#ifndef ORCPLAYER_H
#define ORCPLAYER_H
#include"NovicePlayer.h"

class OrcPlayer :public NovicePlayer
{
public:
	OrcPlayer();
	OrcPlayer(int);
	OrcPlayer(int, string);
	OrcPlayer(const OrcPlayer&);
	void setLevel(int);
};
#endif
#ifndef ORCPLAYER_H
#define ORCPLAYER_H
#include"NovicePlayer.h"

class OrcPlayer :public NovicePlayer
{
	private:
	static constexpr int ct[] = {200,50,50,30};
	static constexpr int tz[] = {2,5,12,10};

	public:
	OrcPlayer();
	OrcPlayer(int);
	OrcPlayer(int, string);
	OrcPlayer(const OrcPlayer&);
	void setLevel(int);
	static OrcPlayer* unserialize(string);
};
#endif
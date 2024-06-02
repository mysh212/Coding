// Author : ysh
// 2024/04/09 Tue 21:07:54
#ifndef ORCPLAYER_HR
#define ORCPLAYER_HR
#include"NovicePlayer.h"
#include"OrcPlayer.h"

// class OrcPlayer::OrcPlayer :public NovicePlayer
// {
// public:
	OrcPlayer::OrcPlayer():
		NovicePlayer() {setLevel(1);};
	OrcPlayer::OrcPlayer(int a):
		NovicePlayer(a) {setLevel(a);};
	OrcPlayer::OrcPlayer(int a, string x):
		NovicePlayer(a,x) {setLevel(a);};
	OrcPlayer::OrcPlayer(const OrcPlayer& x):
		NovicePlayer(x) {};
    void OrcPlayer::setLevel(int a) {
        preLevel(a);

        maxhp = ct[0] + tz[0] * getLevel();
        maxmp = ct[1] + tz[1] * getLevel();
        attack = ct[2] + tz[2] * getLevel();
        defense = ct[3] + tz[3] * getLevel();

        setHp(getMaxHP());
        setMp(getMaxMP());
        return;
    }
// };
#endif


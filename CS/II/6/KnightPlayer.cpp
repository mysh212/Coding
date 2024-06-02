// Author : ysh
// 2024/04/09 Tue 21:07:54
#ifndef KNIGHTPLAYER_HR
#define KNIGHTPLAYER_HR
#include"NovicePlayer.h"
#include"KnightPlayer.h"

// class KnightPlayer::KnightPlayer :public NovicePlayer
// {
// public:
	KnightPlayer::KnightPlayer():
		NovicePlayer() {setLevel(1);};
	KnightPlayer::KnightPlayer(int a):
		NovicePlayer(a) {setLevel(a);};
	KnightPlayer::KnightPlayer(int a, string x):
		NovicePlayer(a,x) {setLevel(a);};
	KnightPlayer::KnightPlayer(const KnightPlayer& x):
		NovicePlayer(x) {};
	void KnightPlayer::heal() {
		if(getMp() < getLevel() * 5) return;
		setHp(getHp() + getLevel() * 10);
		setMp(getMp() - getLevel() * 5);
		return;
	}
    void KnightPlayer::setLevel(int a) {
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


// Author : ysh
// 2024/04/09 Tue 21:07:54
#ifndef MAGICIANPLAYER_HR
#define MAGICIANPLAYER_HR
#include"NovicePlayer.h"
#include"MagicianPlayer.h"

// class MagicianPlayer::MagicianPlayer :public NovicePlayer
// {
// public:
	MagicianPlayer::MagicianPlayer():
		NovicePlayer() {setLevel(1);};
	MagicianPlayer::MagicianPlayer(int a):
		NovicePlayer(a) {setLevel(a);};
	MagicianPlayer::MagicianPlayer(int a, string x):
		NovicePlayer(a,x) {setLevel(a);};
	MagicianPlayer::MagicianPlayer(const MagicianPlayer& x):
		NovicePlayer(x) {};
	void MagicianPlayer::pray() {
		if(getHp() < getLevel() * 5) return cerr<<"Hp is not enough.\n",void();
		setMp(getMp() + getLevel() * 10);
		setHp(getHp() - getLevel() * 5);
		return;
	}
    void MagicianPlayer::setLevel(int a) {
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


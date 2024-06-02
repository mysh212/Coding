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
    

    OrcPlayer* OrcPlayer::unserialize(string x) {
        auto f = split(x,",");
        OrcPlayer* ans = new OrcPlayer();
        
        ans->setHp(       stoi(     f.at(0)   )   );
        ans->setMp(       stoi(     f.at(1)   )   );
        ans->setName(               f.at(2)       );
        ans->setExp(      stoi(     f.at(3)   )   );
        ans->setMoney(    stoi(     f.at(4)   )   );
        ans->setAttack(   stoi(     f.at(5)   )   );
        ans->setDefense(  stoi(     f.at(6)   )   );
        ans->setMaxHP(    stoi(     f.at(7)   )   );
        ans->setMaxMP(    stoi(     f.at(8)   )   );
        ans->setLevel(    stoi(     f.at(9)   )   );
        return ans;
    }
// };
#endif


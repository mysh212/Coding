// Author : ysh
// 2024/05/22 Wed 22:47:56




#ifndef DROP_BALLON_H
#define DROP_BALLON_H
#include"../Players/NovicePlayer.h"
#include"drop.cpp"

struct ballon: public drop{

    ballon(int x,int y,pack* backpack,NovicePlayer* player):
        drop(x,y,backpack,player,"ballon") {};

    virtual drop* preinit(int x,int y,NovicePlayer* player,pack* backpack) {
        return static_cast<drop*>(new ballon(x,y,backpack,player));
    }

    virtual void pick() {
        outl(say(got_balloon));
        backpack->append(this);
    }

    void use() {
        // outl(&player);
        outl(say(balloon_hello));
        player->setAttack(player->getAttack() << 1);
    }
};

#endif
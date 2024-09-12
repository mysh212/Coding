// Author : ysh
// 2024/05/22 Wed 22:47:44


#ifndef DROP_FENCE_H
#define DROP_FENCE_H
#include"drop.cpp"
#include"pack.cpp"

struct fence: public drop{

    fence(int x,int y,pack* backpack,NovicePlayer* player):
        drop(x,y,backpack,player,"fence") {};

    drop* preinit(int x,int y,pack* backpack,NovicePlayer* player) {
        return static_cast<drop*>(new fence(x,y,backpack,player));
    }

    void pick() {
        outl(say(get_fence));
        backpack->append(this);
    }

    void use() {
        out(say(use_fence));
        player->setAttack(player->getAttack() + 10);
        return;
    }

    // pair<char,string> serialize() {
    //     return make_pair('1',name + string("|") + to_string(n) + string("|") + to_string(x) + string("|") + to_string(y) + string("|"));
    // }

    // void unserialize() {
        
    // }
};

#endif
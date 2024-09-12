// Author : ysh
// 2024/05/22 Wed 22:05:53

#ifndef DROP_H
#define DROP_H
#include"pack.cpp"

struct drop{
    int n;
    NovicePlayer* player;
    pack* backpack;
    string name;
    int x,y;


    drop(int x,int y,pack* backpack,NovicePlayer* player,string name):
        x(x), y(y), player(player), backpack(backpack), name(name) {};

    virtual drop* preinit(int x,int y,NovicePlayer* player,pack* backpack,string name) {
        return static_cast<drop*>(new drop(x,y,backpack,player,"drop"));
    }

    virtual void pick() {
        outl(say(null_tool));
    }

    virtual void use() {
        outl(say(use_null_tool));
    }

    string serialize() {
        return name + string("|") + to_string(n) + string("|") + to_string(x) + string("|") + to_string(y) + string("|");
    }

    void unserialize(string x,NovicePlayer* player,pack* backpack) {
        
    }
};

#endif
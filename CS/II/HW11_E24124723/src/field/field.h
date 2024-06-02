#ifndef FIELD_H
#define FIELD_H
#include"../../all.h"
#include"../misc/Character.h"
#include"../misc/drop.cpp"
#include"../drops/pack.cpp"
using namespace std;


class field {
    public:
    vector<vector<int>>f;
    vector<vector<Character>>v;
    Character player;
    pack backpack;
    int n,m;
    int x,y;

    static bool check(vector<vector<bool>>&f,int x,int y) {
        const int xx[] = {0,1,0,-1};
        const int yy[] = {1,0,-1,0};
        for(int i = 0;i<=3;i++) {
            int nx = x + xx[i];
            int ny = y + yy[i];


        }
    }

    void setdrop(int x,int y,drop* t) {
        v.at(x).at(y) = Character('D',true,t);
        f.at(x).at(y) = 4;
        return;
    }

    field(int n,int m,int k):
        n(n), m(m), x(1), y(1), player('P',true,new NovicePlayer()), f({
        {1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1}
        }), v(n,vector<Character>(m)) {
            while(k--) {
                int x = rand() % n;
                int y = rand() % m;

                while((f.at(x).at(y) == 1) || (v.at(x).at(y).type != '\0') || (x == this->x && y == this->y)) {
                    x = rand() % n;
                    y = rand() % m;
                }

                Character now;

                int t = rand() % 3;
                
                if(t == 0) now = Character('M',true,new GoblinMonster());
                if(t == 1) now = Character('M',true,new JWMonster());
                if(t == 2) now = Character('M',true,new ZombieMonster());

                v.at(x).at(y) = now;
                f.at(x).at(y) = 2;
            }
        };

    void print() {
        for(int i = max(0,min(n - 5,x - 2));i<max(5,min(n,x + 2 + 1));i++) {
            for(int j = max(0,min(m - 5,y - 2));j<max(5,min(m,y + 2 + 1));j++) {
                if(i == x && j == y) {
                    cout<<"P";
                    continue;
                }
                if(f.at(i).at(j) == 4) cout<<"?";
                if(f.at(i).at(j) == 1) cout<<"#";
                if(f.at(i).at(j) == 2) cout<<(v.at(i).at(j).alive ? "M" : "X");
                if(f.at(i).at(j) == 0) cout<<"_";
                // if(f.at(i).at(j) == 3) cout<<"P";
            }
            cout<<"\n";
        }
    }

    inline bool walk(int i) {
        // debug(f,x,y);
        const int xx[] = {0,1,0,-1};
        const int yy[] = {1,0,-1,0};

        int nx = x + xx[i];
        int ny = y + yy[i];

        if(nx < 0 || ny < 0 || nx >= n || ny >= m) {
            outl("You cannot get through the wall");
            return true;
        }
        if(f.at(nx).at(ny) == 2) {
            cout<<"Battle\n";
            Character *now[2];
            now[0] = &player;
            now[1] = &v.at(nx).at(ny);
            // debug(now[0]->alive);
            Battle tmp(1,1,now);
            if(static_cast<BaseMonster*>(now[1]->pointer)->getHp() == 0) now[1]->alive = 0; // TDL bug in battle
            if(static_cast<NovicePlayer*>(now[0]->pointer)->getHp() == 0) now[0]->alive = 0; // TDL bug in battle

            if(!player.alive) {
                cout<<"Player has no ability to fight.\n";
                exit(0);
            }
            if(!(now[1]->alive)) {
                // exit(2);
                outl(say(win_a_monster));
                // v.at(nx).at(ny) = Character();
                v.at(nx).at(ny) = (rand() & 1 ? Character('D',true,static_cast<drop*>(new ballon(nx,ny,&backpack,static_cast<NovicePlayer*>(player.pointer)))) : Character('D',true,static_cast<drop*>(new fence(nx,ny,&backpack,static_cast<NovicePlayer*>(player.pointer)))));
                f.at(nx).at(ny) = 4;
                // debug('1024');
            }
            // debug('1');
            return true;
        }
        if(f.at(nx).at(ny) == 4) {
            // debug(v.at(nx).at(ny).type);
            // outl(&player);
            static_cast<drop*>(v.at(nx).at(ny).pointer)->pick();
            // debug('1');
            f.at(nx).at(ny) = 0;
            v.at(nx).at(ny) = Character();
            return true;
        }
        if(f.at(nx).at(ny) != 0) return true;

        // f.at(x).at(y) = 0;
        // f.at(nx).at(ny) = 1;
        x = nx,y = ny;
        return false;
    }
};


#endif
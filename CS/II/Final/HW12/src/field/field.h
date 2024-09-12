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
    vector<vector<bool>>mark;
    Character player;
    pack backpack;
    int n,m;
    int x,y;

    string dump() {
        string ans = "";
        debug(1);
        ans += to_string(n) + " " + to_string(m) + "\n";
        repo(&i,f) {
            re(j,m) ans += i.at(j);
            ans += "\n";
        }
        ans += to_string(x) + " " + to_string(y) + "\n";
        re(i,n) {
            re(j,m) {
                if(v.at(i).at(j).type == '\0') continue;
                ans += (v.at(i).at(j).type) + " " + to_string(i) + " " + to_string(j) + " ";
                ans += v.at(i).at(j).dump() + "\n";
                // ans += "\n";
            }
        }
        ans += player.dump() + "\n";
        ans += backpack.dump() + "\n";
        return ans;
    }

    void load(string x) {
        auto ttmp = core::split(x,"\n");
        deque<string> now(all(ttmp));
        auto tmp = core::split(now.at(0)," ");
        n = stoi(tmp.at(0));
        m = stoi(tmp.at(1));
        now.pop_front();
        f = vector<vector<int>>(n,vector<int>(m));
        v.resize(n,vector<Character>(m));
        mark = vector<vector<bool>>(n,vector<bool>(m));
        re(i,n) {
            re(j,m) {
                f.at(i).at(j) = now.at(i).at(j) & 15;
            }
        }
        re(n) now.pop_front();
        tmp = core::split(now.front()," ");
        x = stoi(tmp[0]),y = stoi(tmp[1]);
        now.pop_front();
        while(!now.empty() && now.front()[0] == 'M') {
            auto tt = core::split(now.front()," ");
            int nx = stoi(tt[1]);
            int ny = stoi(tt[2]);
            v.at(nx).at(ny).load(tt[3]);
            now.pop_front();
        }
        // player.load(now.front());
        now.pop_front();
        // backpack.load(now.front());
        debug(now.front());
        now.pop_front();

        debug(f);
        debug(now);
    }

    void check(int x,int y) {
        if(countfloor(x,y) >= 2) return;
        f.at(x).at(y) = 0;
        const int xx[] = {0,1,0,-1};
        const int yy[] = {1,0,-1,0};
        vc<int>tmp(4);
        iota(all(tmp),0);
        random_shuffle(all(tmp));
        // _debug();
        for(int i = 0;i<=3;i++) {
            int nx = x + xx[tmp[i]];
            int ny = y + yy[tmp[i]];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(mark.at(nx).at(ny)) continue;
            mark.at(nx).at(ny) = 1;

            check(nx,ny);
        }
    }

    inline int countfloor(int x,int y) {
        const int xx[] = {0,1,0,-1};
        const int yy[] = {1,0,-1,0};
        int ans = 0;
        for(int i = 0;i<=3;i++) {
            int nx = x + xx[i];
            int ny = y + yy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(!f.at(nx).at(ny)) ans++;
        }
        return ans;
    }

    void place_clear(int x,int y) {
        const int xx[] = {0,1,0,-1};
        const int yy[] = {1,0,-1,0};

        if(!f.at(x).at(y)) return;
        f.at(x).at(y) = 0;
        re(i,4) {
            int nx = x + xx[i];
            int ny = y + yy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            place_clear(nx,ny);
        }
        return;
    }

    void fake() {
        const int xx[] = {0,1,0,-1};
        const int yy[] = {1,0,-1,0};

        
        vc<vc<pair<int,int>>>rre(n,vc<pair<int,int>>(m));
        vc<vc<bool>>mark(n,vc<bool>(m));
        queue<pair<int,int>>q;
        q.emplace(1,1);
        while(!q.empty()) {
            // debug(1);
            auto now = q.front();q.pop();
            int x = now.first;
            int y = now.second;

            if(mark.at(x).at(y)) continue;
            mark.at(x).at(y) = 1;

            if(x == n - 1 && y == m - 1) break;
            
            re(i,4) {
                int nx = x + xx[i];
                int ny = y + yy[i];

                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(mark.at(nx).at(ny) || f.at(nx).at(ny) == 1) continue;

                rre.at(nx).at(ny) = {x,y};
                q.emplace(nx,ny);
            }
        }
        
        pair<int,int>now({n - 1,m - 1});
        while(!(now == make_pair(1,1))) {
            if(f.at(now.first).at(now.second) == 0) f.at(now.first).at(now.second) = 5;
            now = rre.at(now.first).at(now.second);
        }

        // f.at(n - 1).at(m - 1) = 6;
        return;
    }

    void setdrop(int x,int y,drop* t) {
        v.at(x).at(y) = Character('D',true,t);
        f.at(x).at(y) = 4;
        return;
    }

    field(int n,int m,int k):
        n(n), m(m), x(1), y(1), player('P',true,new NovicePlayer()), f(n,vector<int>(m,1)), v(n,vector<Character>(m)), mark(n,vector<bool>(m)) {
            check(1,1);
            place_clear(n - 1,m - 1);
            f.at(n - 1).at(m - 1) = 6;
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
        re(i,5 + 2) out('=');nl;
        for(int i = max(0,min(n - 5,x - 2));i<max(5,min(n,x + 2 + 1));i++) {
            outt(|);
            for(int j = max(0,min(m - 5,y - 2));j<max(5,min(m,y + 2 + 1));j++) {
                if(i == x && j == y) {
                    cout<<"P";
                    continue;
                }
                else if(f.at(i).at(j) == 6) cout<<"K";
                else if(f.at(i).at(j) == 5) cout<<"O";
                else if(f.at(i).at(j) == 4) cout<<"?";
                else if(f.at(i).at(j) == 1) cout<<"#";
                else if(f.at(i).at(j) == 2) cout<<(v.at(i).at(j).alive ? "M" : "X");
                else if(f.at(i).at(j) == 0) cout<<"_";
                // if(f.at(i).at(j) == 3) cout<<"P";
            }
            outt(|);
            cout<<"\n";
        }
        re(i,5 + 2) out('=');nl;
    }

    void _debug() {
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(i == x && j == y) {
                    cout<<"P";
                    continue;
                }
                else if(f.at(i).at(j) == 6) cout<<"K";
                else if(f.at(i).at(j) == 5) cout<<"O";
                else if(f.at(i).at(j) == 4) cout<<"?";
                else if(f.at(i).at(j) == 1) cout<<"#";
                else if(f.at(i).at(j) == 2) cout<<(v.at(i).at(j).alive ? "M" : "X");
                else if(f.at(i).at(j) == 0) cout<<"_";
                // if(f.at(i).at(j) == 3) cout<<"P";
            }
            cout<<"\n";
        }
    }

    inline void win() {
        outt(You win!);
        exit(0);
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
        if(f.at(nx).at(ny) == 6) return win(),true;
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
        if(f.at(nx).at(ny) != 0 && f.at(nx).at(ny) != 5) return true;

        // f.at(x).at(y) = 0;
        // f.at(nx).at(ny) = 1;
        x = nx,y = ny;
        return false;
    }
};


#endif
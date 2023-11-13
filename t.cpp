// Author : ysh
// 2023/11/07 Tue 16:59:26
#include<bits/stdc++.h>
using namespace std;
// map<int,int> m({{1,1},{2,3},{3,6},{4,10},{5,15},{6,21}});
const int m[] = {0,1,3,6,10,15,21};
#include<slow>
#define bar(i) out("+");re(sizeof(i) / sizeof(char) - 1) out(" ");out("+"),nl,out(" "),out(i),nl,out("+");re(sizeof(i) / sizeof(char) - 1) out(" ");out("+");nl;

struct __cin__{
    void tie(auto x) {
        return;
    }
}in;
bool operator>>(__cin__ &in,int &x) {
    re:
    #undef cin
    string t;
    if(!(cin>>t)) outl("Unexpected EOF"),exit(-1);
    repo(&i,t) if(!isdigit(i)) {
        puts("Invalid input");
        goto re;
    }
    x = stoi(t);
    return 1;
}
bool operator>>(__cin__ &in,char &x) {
    cin>>x;
    return 1;
}
#define cin in

const char t[] = {'R','G','B','C','M','Y','K','W','2'};

struct box{
    vector<int>f;
    vc<vc<int>>now;
    vc<vc<int>>ans;
    vc<int>null = {-1};
    bool last = 0;
    vc<bool>disable;
    int n;

    // struct algo{
    //     // complete if I was really boring.
    // };

    function<void()> algo(int x) {
        if(x == 0) return [&] () {
            if(can_draw()) draw_first(x);
            else pick_one(x,estimate(x));
        };
        if(x == 1) return [&] () { // try to get as many whites as possible
            if(!can_draw()) return pick_one(x,estimate(x));
            re(i,n) if(can_pick(i)) repo(&j,ans.at(i)) if(j == 7) return pick_one(x,i);
            return draw_first(x);
        };
        if(x == 2) return [&] () { // try to get as many plus two cards as possible
            if(!can_draw()) return pick_one(x,estimate(x));
            re(i,n) if(can_pick(i)) repo(&j,ans.at(i)) if(j == 8) return pick_one(x,i);
            return draw_first(x);
        };
        if(x == 3) return [&] () { // just doesn't want to let you win
            if(!can_draw()) return pick_one(x,estimate(x));
            if(f.back() == -10) return draw_first(x);
            if(now.at(n - 1).at(f.back()) == 0) return draw_first(x);
            else re(i,n) if(can_draw(i) && ans.at(i) != null) repo(&j,ans.at(i)) if(now.at(n - 1).at(j) == 0) return printf("Algo %d drew card %c to row %d",x + 1,t[f.back()],i + 1),check(x,0,i);
            return draw_first(x);
        };
    }
    
    box(int n) {
        srand(time(NULL));
        this->n = n;
        disable.resize(n);
        ans.resize(n);
        now = vc<vc<int>>(n,vc<int>(9));
        int toss = -1;

        vc<bool>mark(9);
        if(n == 3) toss = rand() % 7,mark.at(toss) = 1,printf("Due to there is only %d players, we have tossed the color %c.",n,t[toss]),nl;
        rep(i,n) {
            int tmp = rand() % 9;
            while(mark.at(tmp) || tmp == 7) tmp = rand() % 9;
            now.at(i).at(tmp) = 1;
            mark.at(tmp) = 1;
        }

        re(i,7) re(j,9) {
            if(i == toss) break;
            if(j == 8 && mark.at(i)) continue;
            f.push_back(i);
        }
        re(3) f.pb(7);
        re((!mark.at(8) ? 10 : 9)) f.pb(8);
        srand(time(NULL));
        random_shuffle(all(f));
        f.insert(f.begin() + ((n * 3) + 3),-10);
    }

    void print(int x) {
        re(50) out("=");
        nl;
        printf("Players' Hands:\n");
        re(20) printf("-");
        printf("\n");
        re(5) printf(" ");
        rep(i,9) printf("%c  ",t[i]);
        printf("\n");
        rep(i,n) {
            printf("%cP%d  ",(disable.at(i) ? 'x' : (i == x ? '>' : ' ')),i + 1);
            repo(&j,now.at(i)) {
                printf("%d  ",j);
            }
            printf("\n");
        }
        re(20) printf("-");
        printf("\n");

        printf("\nrows:\n");
        re(20) printf("-");
        printf("\n");
        rep(i,n) {
            printf(" Row%d ",i + 1);
            if(ans.at(i) == null) re(5) printf("-");
            repo(j,ans.at(i)) printf("%c ",t[j]);
            printf("\n");
        }

        out("+  +");
        nl;
        printf(" %d cards in the card pile.",f.size());
        nl;
        out("+  +");
        nl;
        return;
    }

    void ask() {
        re(30) out("=");
        nl;
        out("Please enter the corresponding number to have your choice executed.\n");
        nl;
        
        re(20) printf("-");
        printf("\n");

        vc<bool>mark(n + 1);
        rep(i,n) if(ans.at(i).size() == 3) printf("%d) Take everything in row %d.",i + 1,i + 1),nl,mark.at(i + 1) = 1;
        rep(i,n) if(ans.at(i) == null) mark.at(i) = 1;
        if(!f.empty() && can_draw()) out("0) Draw a card from the card pile"),nl,mark.at(0) = 1;
        
        re(20) printf("-");
        printf("\n");

        int tmp;
        while(cin>>tmp) {
            if(tmp < 0 || tmp > n) {
                puts("input again");
                continue;
            }
            if(!mark.at(tmp)) {
                puts("input again");
                continue;
            }
            break;
        }

        check(n - 1,tmp);
        return;
    }

    void add(int x) {
        printf("You got card %c, which row would you like put it in: ",t[x]);nl;
        vc<bool>mark(n);
        rep(i,n) if(not(ans.at(i).size() == 3 || ans.at(i) == null)) printf("%d) put it in row %d.",i + 1,i + 1),nl,mark.at(i) = 1;
        int tmp;
        while(cin>>tmp) {
            if(tmp <= 0 || tmp > n || !mark.at(tmp - 1)) out("input again."),nl;
            else break;
        }
        ans.at(tmp - 1).push_back(x);
    }

    void check(int x,int o,int to = -1) {
        assert(x >= 0 && x <= n - 1);
        assert(o >= 0 && o <= n);
        if(o != 0) {
            o--;
            // printf("vector %d has size %d",o,ans.at(o).size());
            assert(ans.at(o).size() == 3);
            repo(i,ans.at(o)) {
                // printf("Adding %d",i);
                now.at(x).at(i)++;
            }
            ans.at(o) = null;
            disable.at(x) = 1;
            return;
        }
        assert(!f.empty());
        if(f.back() == -10) {
            last = 1;
            bar("Final Round");
            f.pop_back();
        }
        if(to == -1) add(f.back());
        else ans.at(to).push_back(f.back());
        f.pop_back();
    }

    void reset() {
        ans = vc<vc<int>>(n);
        disable = vc<bool>(n);
    }

    bool end() {
        bool c = 1;
        {
            bool o = 1;
            rep(i,n) if(!disable.at(i)) o = 0;
            c = o;
        }
        return c;
    }

    bool can_pick(int x) {
        assert(x >= 0 && x < n);
        return ans.at(x).size() == 3;
    }

    void pick_first(int x) {
        assert(x >= 0 && x < n);
        rep(i,n) if(can_pick(i)) {
            printf("Algo %d picked row %d up.",x + 1,i + 1);nl;
            check(x,i + 1);
            break;
        }
        return;
    }

    void pick_one(int x,int y) {
        assert(x >= 0 && x < n);
        assert(y >= 0 && y < n);
        assert(can_pick(y));
            printf("Algo %d picked row %d up.",x + 1,y + 1);nl;
            check(x,y + 1);
        return;
    }

    bool can_draw(int x = -1) {
        assert(x >= -1 && x < n);
        if(x == -1) {
            repo(i,ans) if(i != null && i.size() != 3) return 1;
            return 0;
        }
        return ans.at(x) != null && ans.at(x).size() < 3;
    }

    void draw_first(int x) {
        assert(can_draw());
        rep(i,n) if(can_draw(i)) {
            printf("Algo %d drew card %c to row %d",x + 1,(f.back() == -10 ? t[*prev(prev(f.end()))] : t[f.back()]),i + 1);nl;
            check(0,0,i);
            break;
        }
        return;
    }

    int calc(vector<int>&f,int up,int tr) {
        debug(f,up,tr);
        assert(is_sorted(f.rbegin(),f.rend()));
        int ans = 0;
        repo(&i,f) while(i < 6 && tr > 0) i++,tr--;
        for(int i = 0;i<3;i++) {
            ans = ans + m[min(f.at(i),6)];
        }
        for(int i = 3,len = f.size();i<len;i++) {
            ans = ans - m[min(f.at(i),6)];
        }
        return ans + (up << 1);
    }

    int calc(vector<int>f) {
        int up = f.back();f.pop_back();
        int tr = f.back();f.pop_back();
        sort(rall(f));
        return calc(f,up,tr);
    }

    int estimate(int x) {
        assert(x >= 0 && x < n);
        vector<pair<int,int>>v;
        auto tmp = now.at(x);
        rep(i,n) if(can_pick(i)) {
            repo(j,ans.at(i)) tmp.at(j)++;
            v.push_back({calc(tmp),i});
            repo(j,ans.at(i)) tmp.at(j)--;
        }
        assert(!v.empty());
        return max_element(all(v))->second;
    }

    void scr() {
        re(70) out("=");
        nl;
        bar("Game Over");
        vc<pair<int,int>>ans;
        int t = 0;
        repo(&i,now) ans.push_back({t++,calc(i)});
        sort(all(ans),[] (pair<int,int>&a,pair<int,int>&b) {
            return a.second > b.second;
        });
        out(" Results:");nl;
        re(30) out("-");nl;
        out("     Rank   Player  Score");nl;
        out("+                         +");nl;
        t = 0;
        repo(&i,ans) printf("    Rank%d     P%d     %d",++t,i.first + 1,i.second),nl;
        printf(" Note that you are the player %d",n);nl;
    }
    int c = 0,d = 0;
    void walk(int x = -1) {
        if(x == -1) x = n - 1;
        // print();
        debug(end());
        // printf("[player %d]",x);
        x = x % n;
        d++;
        debug(last);
        if(last) {bar("Final Round")};
        if(end() && last) return printf("Game over by player %d.",x + 1),nl,scr();
        if(end()) c++,reset();
        if(disable.at(x)) return walk(x + 1);
        if(x != n - 1) {
            puts("+              +");
            printf(" Algo %d's Round",x + 1);nl;
            puts("+              +");



            // if(can_draw()) draw_first(x);
            // else pick_one(x,estimate(x));
            print(x);
            algo(x)();
            // if(last && x == n - 2) return scr();
            return walk(x + 1);
        } else {
            out("+              +");nl;
            out(" Player's Round ");nl;
            out("+              +");nl;
            print(x);
            debug(x,disable);
            debug((disable.at(x) ? 1 : 0));
            debug(c,d);
            ask();
            return walk(x + 1);
        }
    }
};
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    //debug
    // box f = box(4);
    // for(auto &i : f.now) {
    //     for(auto &j : i) {
    //         cin>>j;
    //     }
    // }
    // f.scr();
    // return 2;

    redo:
    out("Input the number of players: ");
    int n;cin>>n;

    if(n < 2 || n > 5) {
        puts("Due to the game rule, the number of players should only be in [2,5].");
        goto redo;
    }
    {
    int tmp = rand() % n;
    printf("You are P%d, and you'll start after %d round.",n,n - (tmp + 1));nl;
    box(n).walk(tmp);
    }
    out("Would you like to play again? [y/N]");
    char tmp;cin>>tmp;
    if(tmp == 'Y' || tmp == 'y') goto redo;
    return 0;
}
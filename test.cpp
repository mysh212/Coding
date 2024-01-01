// Author : ysh
// 2023/12/25 Mon 13:23:48
#include<iostream>
#include<vector>
#include<assert.h>

using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

const int xx[] = {-1,0,1,0,1,-1,1,-1};
const int yy[] = {0,1,0,-1,1,1,-1,-1};

#undef N
#undef M
#undef TIMES
#undef inside

#define N 7
#define M 6
#define TIMES 1
#define inside(i,j) ((i >= 0 && i < N && j >= 0 && j < M))

#ifndef AUTO
#define Player1 player
#define Player2 player
#endif
bool check_buttom(vector<vector<int>>&f) {
    for(auto &i : f) {
        int last = 0;
        for(int &j : i) {
            if(last != 0 && j == 0) return false;
            last = j;
        }
    }
    return true;
}
inline bool check_win(vector<vector<int>>&f,int c) {
    for(int i = 0;i<N;i++) {
        for(int j = 0;j<M;j++) {
            if(f.at(i).at(j) != c) continue;
            for(int k = 0;k<=7;k++) {
                for(int l = 0;l<=3;l++) {
                    // debug(i,j,k,l,c);
                    int nx = i + (xx[k] * l);
                    int ny = j + (yy[k] * l);

                    if(!inside(nx,ny)) break;
                    if(f.at(nx).at(ny) != c) break;
                    if(l == 3) return true;
                }
            }
        }
    }
    return false;
}
inline bool check_filled(vector<vector<int>>&f) {
    for(int i = 0;i<N;i++) {
        for(int j = 0;j<M;j++) {
            if(f.at(i).at(j) == 0) return false;
        }
    }
    return true;
}
inline bool check_only_one_move(vector<vector<int>>&last,vector<vector<int>>&f,int c) {
    // debug(last,f);
    int diff = 0;
    for(int i = 0;i<N;i++) {
        for(int j = 0;j<M;j++) {
            if(last.at(i).at(j) == 0 && f.at(i).at(j) == c) diff++;
            else if(last.at(i).at(j) != f.at(i).at(j)) return false;
        }
    }
    if(diff != 1) return false;
    return true;
}
short check(vector<vector<int>>&last,vector<vector<int>>&f,int c) {
    // debug(c);
    assert(!check_win(last,c));
    if(!check_buttom(f)) return cerr<<"Invalid board\n",-1;
    if(!check_only_one_move(last,f,c)) return cerr<<"Invalid movement\n",-1;

    if(check_win(f,c)) return 1;
    return 0;
}
void pc(vector<vector<int>>&f) {
    for(int i = 0;i<M;i++) {
        for(int j = 0;j<N;j++) {
            if(f.at(j).at(i) == 0) cout<<"_ ";
            else cout<<(f.at(j).at(i) == 1 ? 1 : 2)<<" ";
        }
        cout<<"\n";
    }
    for(int i = 1;i<(N << 1);i++) cout<<'-';
    cout<<"\n";
    for(int i = 1;i<=N;i++) cout<<i<<" \n"[i == N];
    return;
}
void player(vector<vector<int>>&f,int c,int ot) {
    cerr<<"=== Player "<<(c == 1 ? 1 : 2)<<" ===\n";
    cerr<<"Input the number of line you want to walk: ";
    assert(!check_filled(f));
    int n;
    while(cin>>n) {
        if(n >= 1 && n <= N) {
            for(int i = M - 1;i>=0;i--) {
                if(f.at(n - 1).at(i) == 0) {
                    f.at(n - 1).at(i) = c;
                    goto yes;
                }
            }
            goto no;

            yes:
            break;

            no:;
        }
        cerr<<"Input again.\n";
    }

    return;
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    vector<vector<int>>last,f(N,vector<int>(M));

    int n = TIMES;
    int a,b;a = b = 0;
    int both = 0;
    int t = 0;
    while(n--) {
        cout<<"[Round "<<t + 1<<"]\n";
        f = vector<vector<int>>(N,vector<int>(M));
        while(1) {
            int now = ((t + 1) & 1 == 1 ? 1 : -1);
            int ot = -now;
            for(int i = 0;i<=1;i++) {
                last = f;
                pc(f);
                if(now == 1) Player1(f,now,ot);
                else Player2(f,now,ot);
                short res = check(last,f,now);
                if(res == -1) {
                    cerr<<"[Game Number "<<++t<<" : Player"<<(now == 1 ? 2 : 1)<<" wins.]\n";
                    if(now == 1) b++;
                    else a++;
                    goto todo;
                }
                if(res == 1) {
                    cerr<<"[Game Number "<<++t<<" : Player"<<(now == 1 ? 1 : 2)<<" wins.]\n";
                    if(now == 1) a++;
                    else b++;
                    goto todo;
                }
                assert(res == 0);
                swap(now,ot);
                if(check_filled(f)) {
                    both++;
                    cerr<<"[Game Number "<<++t<<" : Drawed.]\n";
                    goto todo;
                }
            }
        }
        todo:
        pc(f);
        continue;
    }

    cout<<"Final result: \n";
    cout<<"Player 1 wins: "<<a<<" times.\n";
    cout<<"Player 2 wins: "<<b<<" times.\n";
    cout<<"Draw: "<<both<<" times.\n";
    return 0;
}
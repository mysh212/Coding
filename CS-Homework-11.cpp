// Author : ysh
// 2024/01/03 Wed 17:32:06
#include<bits/stdc++.h>
using namespace std;
#include<slow>
#define fs first
#define sd second
#ifndef LOCAL
#undef assert
#define assert(...)
#endif

#ifdef LOCAL
#define RAND_SEED 10
#else
#define RAND_SEED time(NULL)
#endif

#define DEEP_P1 6
#define DEEP_P2 2
#define AUTO_GAP 5
#define ALLOW_RANDOM 1
#define LINE_SCORE 50
#define DC_SCORE 3
#define BL_SCORE 0
#define SL_SCORE 0
#define CR_COUNT 10
#define WIN_SCORE 47
#define ALLOW_GAP 10
#define MAX 3

// #define ALLOW_TEST
#define TEST DEEP_P1
#define TEST_MIN 1
#define TEST_MAX 6
#define TIMES 30

pair<int,int> operator+ (pair<int,int>a,pair<int,int>b) {
	return {a.first + b.first,a.second + b.second};
}

struct box_E24124723{
    const int xx[8] = {1,0,-1,0,1,1,-1,-1};
    const int yy[8] = {0,1,0,-1,1,-1,1,-1};

    vector<vector<int>>f;
    int n,m,d,c,ot;

    box_E24124723(vector<vector<int>>f,int c,int ot,int d = 0):
        f(f), n(f.size()), m(f.at(0).size()), d(d), c(c), ot(ot) {};

    inline bool isfilled(int x) {
        assert(x >= 0 && x <= m - 1);
        return !(f.at(0).at(x) == 0);
    }

    inline int topmost(int x) {
        assert(x >= 0 && x < m);
        assert(!isfilled(x));
        // if(isfilled(x)) return -1;

        for(int i = n - 1;i>=0;i--) {
            if(f.at(i).at(x) == 0) return i;
        }
        return -1;
    }

    vector<vector<int>> place(int a,int b,int c) {
        assert(topmost(a) == b);

        vector<vector<int>>tmp(f);
        tmp.at(b).at(a) = c;

        return tmp;
    }

    vector<pair<int,vector<vector<int>>>> walk() {
        vc<pair<int,vc<vc<int>>>>ans;
        re(i,m) if(!isfilled(i)) ans.push_back({i,place(i,topmost(i),c)});
    // exit(-1);
        return ans;
    }

    int check() {
        int ans = 0;
        re(i,n) re(j,m) {
            if(f.at(i).at(j) == 0) continue;
            // int now = 0;
            re(k,8) {
                re(l,4) {
                    int x = i + (xx[k] * l);
                    int y = j + (yy[k] * l);

                    if(x < 0 || x >= n || y < 0 || y >= m) break;
                    if(f.at(x).at(y) != f.at(i).at(j)) break;
                    if(l == 3 && f.at(i).at(j) == c) ans += LINE_SCORE;
                    if(l == 3 && f.at(i).at(j) == ot) ans -= LINE_SCORE;
                }
            }
        }
        // repo(&i,f) outl(i);
        // outl(ans);
        return ans;
    }

    int pick() {
        assert(d != 0);

        vc<pair<pair<int,vc<vc<int>>>,pair<int,int>>>ans;
        
        {
            vc<pair<int,vc<vc<int>>>>tmp(walk());
            repo(&i,tmp) ans.push_back({i,{0,0}});
            if(tmp.empty()) return 1;
        }

        repo(&i,ans) i.second = box_E24124723(i.first.second,ot,c,d - 1)();

        pair<int,int>aans = {0,0};
        repo(&i,ans) aans = aans + i.second;

        if(ALLOW_RANDOM) random_shuffle(all(ans));
        return max_element(all(ans),[] (pair<pair<int,vc<vc<int>>>,pair<int,int>>a,pair<pair<int,vc<vc<int>>>,pair<int,int>>b) {
            return a.second.first * b.second.second > b.second.first * a.second.second;
        })->first.first;
    }

    pair<int,int> operator()() {
        if(d == 0) return {check(),1};

        vc<pair<pair<int,vc<vc<int>>>,pair<int,int>>>ans;
        
        {
            vc<pair<int,vc<vc<int>>>>tmp(walk());
            repo(&i,tmp) ans.push_back({i,{0,0}});
            if(tmp.empty()) return {-100,1};
        }

        repo(&i,ans) i.second = box_E24124723(i.first.second,ot,c,d - 1)();

        pair<int,int>aans = {0,0};
        repo(&i,ans) aans = aans + i.second;

        aans.first = -aans.first;
        return aans;
    }
};

int t_E24124723 = 0;
int player(const vector<vector<char>>&f,char c,char ot) {
	srand(RAND_SEED + t_E24124723++);

    const int N = 6;
    const int M = 7;

    vector<vector<int>>v(N,vector<int>(M));
    for(int i = 0;i<N;i++) {
        for(int j = 0;j<M;j++) {
            if(f.at(i).at(j) == c) v.at(i).at(j) = 1;
            if(f.at(i).at(j) == ot) v.at(i).at(j) = 2;
        }
    }

	auto now = box_E24124723(v,1,2,DEEP_P1);
	return now.pick();
}

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

    
// }
// Author : ysh
// 10/18/2022 Tue 16:24:07.30
// https://www.luogu.com.cn/problem/P1993
#include<bits/stdc++.h>
using namespace std;
#include<fast>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a = readint();
    int b = readint();
    cerr<<a<<" "<<b<<"\n";
    vector<vector<pair<int,int>>>f(a + 1);
    for(int i = 1;i<=a;i++) f[0].push_back({i,0});
    for(int i = 1;i<=b;i++) {
        int a = readint();
        int b = readint();
        int c = readint();
        // b--;c--;
        if(a == 3) {
            f.at(b).push_back({c,0});
            f.at(c).push_back({b,0});
            continue;
        }
        int d = readint();
        if(a == 1) f.at(c).push_back({b,d});
        if(a == 2) f.at(b).push_back({c,-d});
    }
    // vector<bool>mark(a + 1);
    vector<int>dt(a + 1);
    for(int i = 0;i<a;i++) {
        bool c = 0;
        for(int j = 0;j<=a;j++) {
            for(auto i : f.at(j)) {
                if(dt.at(j) + i.second > dt.at(i.first)) {
                    dt.at(i.first) = dt.at(j) + i.second;
                    c = 1;
                }
            }
        }
        if(!c) break;
    }
    for(int j = 0;j<=a;j++) {
        for(auto i : f.at(j)) {
            if(dt.at(j) + i.second > dt.at(i.first)) {
                puts("No");
                return 0;
            }
        }
    }
    puts("Yes");
    return 0;
}
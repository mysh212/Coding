// Author : ysh
// 01/25/2023 Wed 20:29:20.82
// https://codeforces.com/contest/1792/problem/D
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int a,b;cin>>a>>b;
        vector<vector<int>>f(a,vector<int>(b));
        vector<set<vector<int>>>s(10);
        vector<int>tmp(b);
        for(int i = 0;i<a;i++) {
            tmp = vector<int>(b);
            for(int j = 0;j<b;j++) {
                cin>>f.at(i).at(j);
                f.at(i).at(j)--;
                tmp.at(f.at(i).at(j)) = j;
            }
            vector<int>t;
            for(int j = 0;j<b;j++) {
                t.push_back(tmp.at(j));
                s.at(j).insert(t);
            }
            // for(int &i : t) cerr<<i<<" ";
            // cerr<<"\n"<<flush;
        }
        // debug(s);
        for(int i = 0;i<a;i++) {
            vector<int>tmp;
            for(int j = 0;j<=b;j++) {
                if(j == b) {
                    cout<<b<<" ";
                    break;
                }
                tmp.push_back(f.at(i).at(j));
                if(s.at(j).find(tmp) == s.at(j).end()) {
                    cout<<j<<" ";
                    break;
                }
            }
        }
        cout<<"\n";
    }
    return 0;
}
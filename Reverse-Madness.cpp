// Author : ysh
// 09/28/2023 Thu 13:54:12.69
// https://codeforces.com/contest/1878/problem/D
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
        int n,m;cin>>n>>m;
        string a;cin>>a;
        vector<bool>f(n),mark(n);
        vector<pair<int,int>>v(m);
        for(auto &i : v) {
            cin>>i.first;
            i.first--;
        }
        for(auto &j : v) {
            cin>>j.second;
            j.second--;
        }

        int r;cin>>r;
        while(r--) {
            int tmp;cin>>tmp;
            tmp--;
            mark.at(tmp) = !mark.at(tmp);
        }
        debug(mark);

        for(int i = 0;i<m;i++) {
            bool c = 0;
            for(int j = v.at(i).first;j<=((v.at(i).first + v.at(i).second) >> 1);j++) {
                int k = (v.at(i).first + v.at(i).second) - j;
                if(c) swap(a.at(j),a.at(k));
                if(mark.at(j)) swap(a.at(j),a.at(k));
                if(mark.at(k)) swap(a.at(j),a.at(k));
                c = c ^ mark.at(j) ^ mark.at(k);
                cout<<a.at(j);
            }
            for(int j = ((v.at(i).first + v.at(i).second) >> 1) + 1;j<=v.at(i).second;j++) {
                cout<<a.at(j);
            }
        }
        cout<<"\n";
    }
    return 0;
}
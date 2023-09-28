// Author : ysh
// 09/28/2023 Thu 13:54:12.69
// https://codeforces.com/contest/1878/problem/D
// NF
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
        vector<bool>f(n),mark(m);
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
            auto found = lower_bound(v.rbegin(),v.rend(),make_pair(tmp,n - 1),[](pair<int,int>a,pair<int,int>b) {
                return a.first > b.first;
            });
            // assert(next(found) != v.begin());
            int now = (m - 1) - (found - v.rbegin());
            // cerr<<"now: "<<now<<"\n";
            mark.at(now) = !mark.at(now);
        }
        debug(mark);

        for(int i = 0;i<m;i++) {
            if(!mark.at(i)) {
                for(int j = v.at(i).first;j<=v.at(i).second;j++) {
                    cout<<a.at(j);
                }
                continue;
            }
            for(int j = v.at(i).second;j>=v.at(i).first;j--) {
                cout<<a.at(j);
            }
        }
        cout<<"\n";
    }
    return 0;
}
// Author : ysh
// 02/23/2022 Wed 12:53:30.57
// https://judge.tcirc.tw/ShowProblem?problemid=d016
// TLE
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //freopen("Q.in","r",stdin);
    //auto aaa = clock();
    int a,b,ans = 0;cin>>a>>b;
    const int mmax = (1<<a) - 1;
    int c[b] = {};
    int l[b] = {};
    bitset<26>f[b];
    string tmp;
    for(int i = 0;i<b;i++) {
        cin>>tmp;
        l[i] = tmp.size();
        for(char j : tmp) {
            int now = (int) j - (int) 'A';
            f[i].set(now);
        }
        l[i] = f[i].count();
    }
    bitset<26>e;
    for(int i = 0;i<b;i++) {
        for(int j = i+1;j<b;j++) {
            if(l[i] + l[j] != a) continue;
            e.reset();
            for(auto k = f[i]._Find_first();k<26;k = f[i]._Find_next(k)) {
                e.set(k);
            }
            for(auto k = f[j]._Find_first();k<26;k = f[j]._Find_next(k)) {
                e.flip(k);
            }
            if(e.count() == a) ans++;
        }
    }
    cout<<ans;
    //cout<<clock() - aaa;
    return 0;
}
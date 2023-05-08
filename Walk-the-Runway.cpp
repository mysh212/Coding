// Author : ysh
// 05/08/2023 Mon 11:41:37.08
// https://codeforces.com/contest/1826/problem/E
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif
// #include<fast>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>g(b);
    for(int &i : g) {
        cin>>i;
    }
    bitset<5000>tmp;
    tmp.set();
    vector<bitset<5000>>f(5000,tmp);
    vector<pair<int,int>>mark;
    for(int i = 0;i<a;i++) {
        vector<int>now(b);
        mark = vector<pair<int,int>>(b);
        int t = 0;
        for(int &i : now) {
            cin>>i;
            mark[t] = {i,t};
            t = t + 1;
        }
        sort(mark.begin(),mark.end());
        bitset<5000>s;
        s.set();
        for(int j = 0;j<b;j++) {
            s.reset(mark.at(j).second);
            int r = j;
            while(r < b && now.at(mark.at(r).second) == now.at(mark.at(j).second)) {
                s.reset(mark.at(r).second);
                r++;
            }
            for(int k = j;k<r;k++) f.at(mark.at(k).second) = f.at(mark.at(k).second) & s;
            j = r - 1;
        }
    }

    vector<long long>in(b);
    vector<int>mk,trace;
    queue<int>q;
    for(int i = 0;i<b;i++) {
        for(int j = 0;j<b;j++) {
            if(f[j][i]) in[i]++;
        }
        if(in[i] == 0) q.push(i),trace.push_back(i);
    }
    debug(in);
    while(!q.empty()) {
        int now = q.front();q.pop();
        mk.push_back(now);
        for(int i = 0;i<b;i++) {
            if(f[now][i]) {
                if(--in[i] == 0) {
                    q.push(i);
                }
            }
        }
    }
    debug(mk);
    reverse(mk.begin(),mk.end());
    in = vector<long long>(b);
    for(int &i : mk) {
        for(int j = 0;j<b;j++) {
            if(f[i][j]) {
                in[i] = max(in[i],in[j]);
            }
        }
        in[i] = in[i] + max(0LL,g[i] * 1LL);
    }
    long long mmax = 0;
    for(int &i : trace) {
        mmax = max(mmax,in[i]);
    }
    cout<<mmax;
    // cout<<in[mk.back());
    // for(int i = 0;i<b;i++) {
    //     for(int j = 0;j<b;j++) {
    //         cout<<(int) f[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    return 0;
}
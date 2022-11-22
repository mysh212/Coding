// Author : ysh
// 11/22/2022 Tue  9:23:57.92
// https://codeforces.com/contest/1760/problem/D
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
        int n;cin>>n;
        vector<bool>r;
        {
        int last;
        cin>>last;
        if(n == 1) {
            cout<<"YES\n";
            continue;
        }
        n = n - 1;
        r.push_back(0);
        while(n--) {
           int tmp;cin>>tmp;
           if(last == tmp) continue;
           if(last > tmp) r.push_back(0);
           if(last < tmp) r.push_back(1); 
           last = tmp;
        }
        }
        r.push_back(1);
        debug(r);
        bool ans = 1;
        bool cg = 0;
        bool last = r.at(0);
        for(bool i : r) {
            if(last == i) continue;
            last = i;
            if(cg) {
                ans = 0;
                continue;
            }
            cg = 1;
        }
        cout<<array<string,2>({"YES","NO"})[!ans]<<"\n";
    }
    return 0;
}
// Author : ysh
// 2023/07/31 Mon 21:09:00
// https://codeforces.com/contest/1743/problem/D
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<bool>f(n);
    int l = -1,r = -2;
    for(int i = 0;i<n;i++) {
        char tmp;cin>>tmp;
        f.at(i) = (tmp == '1');
        if(f.at(i) && l == -1) l = i;
    }
    if(l == -1) return cout<<0,0;

    for(int i = l;i<n;i++) {
        if(!f.at(i)) {
            r = i;
            break;
        }
    }
    if(r == -2) {
        for(int i = l;i<n;i++) cout<<1;
        return 0;
    }

    vector<bool>mmax = f;

    function<void(int,int)> check = [&] (int x, int p) {
        // cerr<<x<<" "<<p<<"\n";
        bool c = 0;
        for(int i = x;i < n && p < n;i++,p++) {
            if(!c && (mmax.at(p) && (!f.at(i) && !f.at(p)))) return;
            if(!mmax.at(p) && (f.at(i) || f.at(p))) c = 1;
            if(c) mmax.at(p) = f.at(i) | f.at(p);
        }
        return;
    };

    for(int i = l;i<r;i++) {
        check(i,r);
    }

    for(int i = l;i<n;i++) {
        cout<<(mmax.at(i) ? '1' : '0');
    }
    return 0;
}
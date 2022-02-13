// Author : ysh
// 02/13/2022 Sun 14:49:28.75
// https://codeforces.com/group/H0qY3QmnOW/contest/366708/problem/E
#include<bits/stdc++.h>
using namespace std;
int a,b;
int mmin = INT_MAX;
int amin,bmin;
bool brk = 0;
void check(int now,int ar,int br) {
    if(ar > 10||br > 10) return;
    if(brk) return;
    if(mmin == 0) {
        brk = 1;
        return;
    }
    if(now < 0) {
        return;
    }
    if(now < mmin) {
        amin = ar;
        bmin = br;
        mmin = now;
    }
    check(now - a,ar + 1,br);
    check(now - b,ar,br + 1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c,d;cin>>c>>d>>a>>b;
    c = c - d;
    check(c,0,0);
    cout<<amin<<" "<<bmin<<" "<<mmin;
    return 0;
}
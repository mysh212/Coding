// Author : ysh
// 10/24/2022 Mon  8:16:27.70
#include<bits/stdc++.h>
using namespace std;
vector<vector<bool>>f;
int a,b,c;
int ans = 0;
bool A(int r) {
    if(r < 0 || r + 3 >= a) return 0;
    int lss = -1;
    for(int i = 0;i<b;i++) {
        if(!(f[r][i] || f[r + 1][i] || f[r + 2][i] || f[r + 3][i])) lss = i;
        else break;
    }
    if(lss == -1) return 0;
    f[r][lss] = f[r + 1][lss] = f[r + 2][lss] = f[r + 3][lss] = 1;
    ans -= 4;
    return 1;
}
bool B(int r) {
    if(r < 0 || r >= a) return 0;
    int lss = -1;
    for(int i = 0;i + 2<b;i++) {
        if(!(f[r][i] || f[r][i + 1] || f[r][i + 2])) lss = i;
        else break;
    }
    if(lss == -1) return 0;
    f[r][lss] = f[r][lss + 1] = f[r][lss + 2] = 1;
    ans -= 3;
    return 1;
}
bool C(int r) {
    if(r < 0 || r + 1 >= a) return 0;
    int lss = -1;
    for(int i = 0;i + 1<b;i++) {
        if(!(f[r][i] || f[r][i + 1] || f[r + 1][i] || f[r + 1][i + 1])) lss = i;
        else break;
    }
    if(lss == -1) return 0;
    f[r][lss] = f[r][lss + 1] = f[r + 1][lss] = f[r + 1][lss + 1] = 1;
    ans -= 4;
    return 1;
}
bool D(int r) {
    if(r < 0 || r + 1 >= a) return 0;
    int lss = -1;
    for(int i = 0;i + 2<b;i++) {
        if(!(f[r][i] || f[r + 1][i] || f[r + 1][i + 1] || f[r + 1][i + 2])) lss = i;
        else break;
    }
    if(lss == -1) return 0;
    f[r][lss] = f[r + 1][lss] = f[r + 1][lss + 1] = f[r + 1][lss + 2] = 1;
    ans -= 4;
    return 1;
}
bool E(int r) {
    if(r < 0 || r + 2 >= a) return 0;
    int lss = -1;
    for(int i = 0;i + 1<b;i++) {
        if(!(f[r][i] || f[r + 1][i] || f[r + 2][i] || f[r + 1][i + 1] || f[r + 2][i + 1])) lss = i;
        else break;
    }
    if(lss == -1) return 0;
    f[r][lss] = f[r + 1][lss] = f[r + 2][lss] = f[r + 1][lss + 1] = f[r + 2][lss + 1] = 1;
    ans -= 5;
    return 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>a>>b>>c;
    ans = a * b;
    f.resize(a,vector<bool>(b));
    int nt = 0;
    for(int i = 0;i<c;i++) {
        char tmp;cin>>tmp;int r;cin>>r;
        if(tmp == 'A') nt += !A(r);
        if(tmp == 'B') nt += !B(r);
        if(tmp == 'C') nt += !C(r);
        if(tmp == 'D') nt += !D(r);
        if(tmp == 'E') nt += !E(r);
    }
    // for(auto i : f) {for(int j : i) cerr<<j<<" "; cerr<<"\n";}
    cout<<ans<<" "<<nt;
    return 0;
}
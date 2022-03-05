// Author : ysh
// 03/04/2022 Fri 22:39:28.25
// http://choj.me/problem/00022
#include<bits/stdc++.h>
using namespace std;
//inline bool cp(int,int);
int m = 0;
inline bool cp(int &a,int &b) {
    m++;
    return a<b;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n);
    for(int &i : f) {
        cin>>i;
    }
    sort(f.begin(),f.end(),cp);
    cout<<::m;
    return 0;
}
// Author : ysh
// 02/13/2022 Sun 15:03:59.52
// https://codeforces.com/group/H0qY3QmnOW/contest/366708/problem/F
#include<bits/stdc++.h>
using namespace std;
bool cp(int &a,int &b) {
    return a>b;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int>f;
    int tmp;
    for(int i = 0;i<10;i++) {
        cin>>tmp;
        f.push_back(tmp);
    }
    sort(f.begin(),f.end());
    int b;cin>>b;
    int c,d;
    while(b--) {
        cin>>c>>d;
        if(c == 1) {
            f.push_back(d);
        } else {
            sort(f.begin(),f.end(),cp);
            cout<<f.at(d - 1)<<"\n";
        }
    }
}
// Author : ysh
// 01/06/2023 Fri 10:13:10.52
// https://open.kattis.com/problems/ninepacks
#include<bits/stdc++.h>
using namespace std;
const int R = 1000 * 100;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n);
    for(int &i : f) {
        cin>>i;
    }
    int m;cin>>m;
    vector<int>g(m);
    for(int &i : g) {
        cin>>i;
    }
    vector<int>ff(R + 1,INT_MAX),gg(R + 1,INT_MAX);
    ff.at(0) = gg.at(0) = 0;
    for(int &i : f) {
        for(int j = R;j >= i;j--) {
            if(ff.at(j - i) == INT_MAX) continue;
            ff.at(j) = min(ff.at(j),ff.at(j - i) + 1);
        }
    }
    for(int &i : g) {
        for(int j = R;j >= i;j--) {
            if(gg.at(j - i) == INT_MAX) continue;
            gg.at(j) = min(gg.at(j),gg.at(j - i) + 1);
        }
    }
    int mmin = INT_MAX;
    for(int i = 1;i<=R;i++) {
        if(ff.at(i) != INT_MAX && gg.at(i) != INT_MAX) {
            mmin = min(ff.at(i) + gg.at(i),mmin);
        }
    }
    if(mmin != INT_MAX) cout<<mmin;
    else cout<<"impossible";
    return 0;
}
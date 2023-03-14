// Author : ysh
// 03/14/2023 Tue 11:50:36.68
// https://judge.tcirc.tw/ShowProblem?problemid=b048
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>f(a);
    for(int &i : f) {
        cin>>i;
    }

    int l = 0,r = a - 1;
    for(;l<a;l++) {
        while(l + 1 < r && f.at(l) + f.at(r) > b) r--;
        if(f.at(l) + f.at(r) == b) {
            cout<<l<<" "<<r<<"\n";
            return 0;
        }
    }
    cout<<"IMPOSSIBLE\n";
    return 0;
}
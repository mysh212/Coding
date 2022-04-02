// Author : ysh
// 03/18/2022 Fri 22:44:10.00
// https://192.168.193.20/problem/16
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,k;cin>>n>>k;
    vector<int>f(n);
    for(int &i : f) {
        cin>>i;
    }
    sort(f.begin(),f.end());
    int tmp;
    for(int i = 0;i<k;i++) {
        cin>>tmp;
        auto found = lower_bound(f.begin(),f.end(),tmp);
        if(*found != tmp) {
            cout<<-1<<"\n";
            continue;
        }
        cout<<found - f.begin()<<"\n";
    }
    return 0;
}
// Author : ysh
// 09/14/2022 Wed  9:55:45.45
#include<bits/stdc++.h>
using namespace std;
#include<seg_tree>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n);
    for(int &i : f) {
        cin>>i;
    }
    seg_tree<int>t(f,[] (int a,int b) {
        return max(a,b);
    });
    int m;cin>>m;
    int a,b;
    while(m--) {
        cin>>a>>b;
        if(a > b) swap(a,b);
        cout<<t.sum(a - 1,b - 1)<<"\n";
    }
    return 0;
}
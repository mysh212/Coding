// Author : ysh
// 09/14/2022 Wed  9:22:50.20
#include<bits/stdc++.h>
using namespace std;
#include<seg_tree>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;
    seg_tree<int>t(100,[] (int a,int b) {
        return max(a,b);
    });
    while(cin>>a>>b>>c) {
        if(a == 1) {
            cerr<<t.sum(b - 1,c - 1);
        }
        if(a == 2) {
            t.add(b - 1,c);
        }
    }
    return 0;
}
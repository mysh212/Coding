// Author : ysh
// 01/19/2023 Thu 15:21:11.29
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
    vector<array<int,3>>v(a - 1);
    for(auto &i : v) {
        cin>>i[0]>>i[1]>>i[2];
        i[0]--;i[1]--;
    }
    for(auto &i : v) {
         
    }
}
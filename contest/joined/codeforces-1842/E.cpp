// Author : ysh
// 2023/06/24 Sat 23:53:25
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;cin>>a>>b>>c;
    vector<array<int,3>>f(a);
    for(auto &i : f) cin>>i[0]>>i[1]>>i[2];

    sort(f.begin(),f.end());
    vector<int>mark;
    for(int i = 0;i<a;i++) {
        if(max(abs(b - f[i][0]),abs(b - f[i][1])) * c <= f[i][2]) mark.push_back(i);
    }
    for(int &i : mark) cout<<i<<" ";
    return 0;
}
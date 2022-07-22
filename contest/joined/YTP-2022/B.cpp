// Author : ysh
// 07/22/2022 Fri 17:50:33
#include<bits/stdc++.h>
using namespace std;
vector<int>f;
void check() {
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    f.resize(n);
    iota(f.begin(),f.end(),0);
    map<pair<int,int>,int>m;
    for(int i = 0;i <= n - 2;i++) {
        m.insert({{f[i],f[i + 1]},1});
    }
}

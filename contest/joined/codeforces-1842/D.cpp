// Author : ysh
// 2023/06/24 Sat 23:43:06
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<vector<pair<int,int>>>f(a);
    for(int i = 0;i<b;i++) {
        int a,b,c;cin>>a>>b>>c;
        a--;b--;
        f.at(a).push_back(make_pair(b,c));
        f.at(b).push_back(make_pair(a,c));
    }

    
}
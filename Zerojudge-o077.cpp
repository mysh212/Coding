// Author : ysh
// 2024/07/24 Wed 23:33:10
#include<bits/stdc++.h>
using namespace std;
#include<slow>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;cin>>a>>b>>c;
    vector<vector<int>>f(a,vector<int>(b));
    re(c) {
        int n,m,k,l;cin>>n>>m>>k>>l;
        re(i,a) re(j,b) if(abs(i - n) + abs(j - m) <= k) f.at(i).at(j) += l;
    }

    repo(&i,f) outl(i);
    return 0;
}
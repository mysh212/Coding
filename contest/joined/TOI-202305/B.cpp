// Author : ysh
// 06/02/2023 Fri 18:19:37.11
#include<bits/stdc++.h>
using namespace std;
vector<int>color;
int ff(int x) {
    if(color.at(x) == x) return x;
    return color.at(x) = ff(color.at(x));
}
void mg(int a,int b) {
    color.at(ff(a)) = ff(b);
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;cin>>a>>b>>c;
    vector<array<int,3>>f(a);
    int last = -1;
    while(c--) {
        int tmp;cin>>tmp;
        if(last == -1) last = tmp - 1;
        else f.push_back({0,tmp - 1,last}),last = tmp - 1;
    }
    
    for(int i = 0;i<b;i++) {
        int a,b,c;cin>>a>>b>>c;
        a--;b--;
        f.push_back({c,a,b});
    }

    sort(f.begin(),f.end());
    color.resize(a);
    iota(color.begin(),color.end(),0);
    int ans = 0;
    for(auto &i : f) {
        if(ff(i[1]) == ff(i[2])) continue;
        mg(i[1],i[2]);
        ans += i[0];
    }
    cout<<ans;
    return 0;
}
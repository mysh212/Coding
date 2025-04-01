// Author : ysh
// 2024/10/23 Wed 23:17:55
#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second

vector<int>color;
int ff(int x) {
    if(color.at(x) == x) return x;
    return color.at(x) == ff(color.at(x));
}
inline void mg(int a,int b) {
    color.at(ff(a)) = ff(b);
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while(cin>>n) {
        vector<pair<pair<int,int>,pair<int,int>>>f(n);
        for(auto &i : f) cin>>i.x.x>>i.x.y>>i.y.x>>i.y.y;
        for(auto &i : f) i.y.x += i.x.x,i.y.y += y.x.y;

        int t = 0;
        vector<array<int,4>>l,r;
        for(auto &i : f) {
            l.push_back({i.x.x,i.x.y,i.y.y,t});
            l.push_back({i.y.x,i.x.y,i.y.y,t});
            r.push_back({i.x.y,i.x.x,i.y.x,t});
            r.push_back({i.y.y,i.x.x,i.y.x,t});
            t++;
        }

        sort(l.begin(),l.end());
        sort(r.begin(),r.end());

    
    }
}
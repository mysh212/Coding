// Author : ysh
// 06/15/2022 Wed 17:12:52.44
#include<bits/stdc++.h>
using namespace std;
class box{
    int x,c;
    bool operator<(box b) {
        return x < b.x;
    }
    explicit box(int a,int b):
        x(a), c(b) {};
};

void check(int&,int&,int&,int&);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    map<int,map<int,int>>m,s;
    int n;cin>>n;
    for(int i = 0;i<n;i++) {
        int a,b,c;
        m[a].emplace(b,c);
        s[b].emplace(a,c);
    }
    int x,y;x=y=0;
    int d = 0;
    int ans = -1;
    while(1) {
        ans++;
        cerr<<x<<" "<<y<<"\n";
        if(d == 0) {
            auto now = s.find(y);
            int nx = 0;
            if(now == s.end()) {
                break;
            }
            cerr<<1;
            auto found = (now->second).upper_bound(x);
            for(auto i : now->second) cout<<i.first <<" ";
            cout<<"\n";
            if(found == now->second.end()) break;
            cerr<<1;
            x = found->first;
            int c = found->second;
            check(c,d,x,y);
        }
        if(d == 1) {
            auto now = m.find(x);
            int nx = 0;
            if(now == m.end()) {
                break;
            }
            auto found = (now->second).upper_bound(y);
            if(found == now->second.end()) break;
            y = found->first;
            int c = found->second;
            check(c,d,x,y);
        }
        if(d == 2) {
            auto now = s.find(y);
            int nx = 0;
            if(now == s.end()) {
                break;
            }
            auto found = prev((now->second).lower_bound(x));
            if(found == --now->second.begin()) break;
            x = found->first;
            int c = found->second;
            check(c,d,x,y);
        }
        if(d == 3) {
            auto now = m.find(x);
            int nx = 0;
            if(now == m.end()) {
                break;
            }
            auto found = prev((now->second).lower_bound(x));
            if(found == --now->second.begin()) break;
            y = found->first;
            int c = found->second;
            check(c,d,x,y);
        }
    }
    cout<<ans;
    return 0;
}

void check(int &c,int &d,int &x,int &y) {
            if(c == 0) {
                if(d == 0) {
                    d = 1;
                } else if(d == 1) {
                    d = 0;
                } else if(d == 2) {
                    d = 3;
                } else {
                    d = 2;
                }
            } else {
                if(d == 0) {
                    d = 3;
                } else if(d == 1) {
                    d = 2;
                } else if(d == 2) {
                    d = 1;
                } else {
                    d = 0;
                }
            }
            return;
}
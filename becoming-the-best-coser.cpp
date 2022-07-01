// Author : ysh
// 07/01/2022 Fri  7:51:16.92
// https://choj.me/problem/c005
#include<bits/stdc++.h>
using namespace std;
struct box{
    int a,b;
    box(int a,int b):
        a(a), b(b) {};
    bool operator<(box b) {
        return a < b.a;
    }
    void check() {
        printf("[%d,%d]\n",a,b);
        return;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m;cin>>m;
    while(m--) {
        int n;cin>>n;
        vector<box>f(n,box(0,0));
        for(box &i : f) {
            cin>>i.b;
        }
        for(box &i : f) {
            cin>>i.a;
            i.a = i.b - i.a;
        }
        sort(f.begin(),f.end());
        // for(auto i : f) {
        //     i.check();
        // }
        map<int,int>m;
        m.insert({INT_MIN,0});
        for(int i = 0;i<n;i++) {
            if(f[i].a < 0) continue;
            auto found = m.upper_bound(f[i].a);
            int last = prev(found)->second + 1;
            if(m.find(f[i].b) == m.end()) m.insert({f[i].b,last});
            else {
                if(m[f[i].b] > last) continue;
                m[f[i].b] = last;
            }
            // cout<<last<<"\n";
            for(auto j = ++m.find(f[i].b);j != m.end();j++) {
                if(last > j->second) j->second = last;
                else break;
            }
            // for(auto i : m) {
            //     cerr<<i.first<<" "<<i.second<<"\n";
            // }
            // cout<<"\n";
        }
        cout<<prev(m.end())->second<<"\n";
    }
    return 0;
}
// Author : ysh
// 07/25/2022 Mon 17:19:30.64
#include<bits/stdc++.h>
using namespace std;
#define int long long
struct box{
    int x = 0,y = 0;
    bool operator<(box a) {
        return x < a.x;
    }
    bool operator<(int a) {
        return x < a;
    }
    box(int x = 0,int y = 0):
        x(x), y(y) {};
};
// inline bool cp(box a,int b) {
//     return a.x < b;
// }
inline bool cp(box a,box b) {
    return a.x < b.x;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<box>f(n);
    for(auto &i :f) {
        cin>>i.x;
    }
    for(auto &i :f) {
        cin>>i.y;
    }
    deque<box>v({{INT_MAX,-1}});
    int ans = 0;
    for(int i = 0;i<n;i++) {
        while((!v.empty()) && (v.front().x <= f.at(i).x)) {
            v.pop_front();
        }
        auto found = upper_bound(v.begin(),v.end(),box(f.at(i).x + f.at(i).y,0),cp);
        ans = ans + ((i - found->y) - 1);
        // cout<<(found - v.begin())<<" ";
        v.push_front({f.at(i).x,i});
    }
    cout<<ans;
    return 0;
}
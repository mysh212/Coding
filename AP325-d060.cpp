// Author : ysh
// 07/24/2022 Sun 18:46:07.83
#include<bits/stdc++.h>
using namespace std;
struct box{
    int x = 0,y = 0,z = 0;
    bool operator<(box a) {
        return x < a.x;
    }
    bool operator() (pair<int,int>a,pair<int,int>b) {
        if(a.first != b.first) return (a.first > b.first);
        return a.second < b.second;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<box>f(n);
    for(box &i : f) {
        cin>>i.z>>i.x>>i.y;
    }
    // sort(f.begin(),f.end());
    int ans = 0;
    // for(int i = 0;i<n;i++) {
    //     int tmp = 0;
    //     int now = f.at(i).x;
    //     for(int j = i;j >= 0;j--) {
    //         if(now > f.at(j).y) {
    //             continue;
    //         }
    //         tmp = tmp + f.at(j).z;
    //     }
    //     ans = max(ans,tmp);
    // }
    priority_queue<pair<int,int>,vector<pair<int,int>>,box>q;
    for(box i : f) {
        q.push({i.x,i.z});
        q.push({i.y,-i.z});
    }
    int sig = 0;
    while(!q.empty()) {
        // cerr<<1;
        auto now = q.top();q.pop();
        sig = sig + now.second;
        ans = max(ans,sig);
    }
    cout<<ans;
    return 0;
}
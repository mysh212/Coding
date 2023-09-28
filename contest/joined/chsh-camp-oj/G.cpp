// Author : ysh
// 2023/07/07 Fri 14:04:42
#include<bits/stdc++.h>
using namespace std;
struct box{
    int l,d,last;
    box(int l = 0,int d = 0,int last = 0):
        l(l), d(d), last(last) {};
    bool operator<(const box a) const {
        if(l == a.l) return d > a.d;
        return l > a.l;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<vector<int>>f(a);
    for(int i = 0;i<b;i++) {
        int a,b;cin>>a>>b;
        a--;b--;
        f.at(a).push_back(b);
        f.at(b).push_back(a);
    }

    vector<int>mark(a,-2);
    priority_queue<box>q;
    q.push(box(0,0,-1));
    while(!q.empty()) {
        auto now = q.top();q.pop();
        int l = now.l;
        int d = now.d;
        int last = now.last;
        if(mark.at(d) != -2) continue;
        mark.at(d) = last;
        for(int &i : f.at(d)) {
            q.push(box(l + 1,i,d));
        }
    }

    if(mark.at(a - 1) != -2) {
        cout<<"YES\n";
        int now = a - 1;
        vector<int>ans;
        while(now != 0) {
            now = mark.at(now);
            ans.push_back(now);
        }
        reverse(ans.begin(),ans.end());
        cout<<ans.size() + 1<<"\n";
        for(int &i : ans) {
            cout<<i + 1<<" ";
        }
        cout<<a;
        return 0;
    }
    cout<<"NO\n";
    return 0;
}
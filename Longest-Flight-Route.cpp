// Author : ysh
// 10/11/2022 Tue 11:42:09.75
// https://cses.fi/problemset/task/1680
// NA
#include<bits/stdc++.h>
using namespace std;
struct box{
    int l,d,last;
    box(int x = 0,int y = 0,int z = 0):
        l(x), d(y), last(z) {};
    bool operator<(const box a) const {
        return l < a.l;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<vector<int>>f(a);
    for(int i = 0;i<a;i++) {
        int a,b;cin>>a>>b;
        a--;b--;
        f.at(a).push_back(b);
    }
    priority_queue<box>q;
    q.emplace(0,0,-1);
    vector<int>re(a,-1);
    vector<bool>mark(a);
    while(!q.empty()) {
        auto now = q.top();q.pop();
        int l = now.l;
        int d = now.d;
        cerr<<d<<" ";
        int last = now.last;
        re.at(d) = last;
        if(mark.at(d)) continue;
        mark.at(d) = 1;
        for(int &i : f.at(d)) {
            q.emplace(l + 1,i,d);
        }
    }
    if(re.at(a - 1) != -1) {
        int r = a - 1;
        vector<int>ans;
        while(r != 0) {
            ans.push_back(r);
            r = re.at(r);
        }
        cout<<ans.size() + 1;
        cout<<"\n1 ";
        while(!ans.empty()) {
            cout<<ans.back() + 1<<" ";ans.pop_back();
        }
        return 0;
    }
    cout<<"IMPOSSIBLE";
    return 0;
}
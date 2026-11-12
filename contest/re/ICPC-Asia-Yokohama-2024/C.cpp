// Author : ysh
// 2026/11/05 Thu 15:35:04
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;cin>>n>>m;
    vector<int> node(n+1),visit(n+1,0);
    vector<vector<pair<int,int> > > nxt(n+1);
    for(int i=1;i<=n;i++) cin>>node[i];
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        nxt[a].push_back({b,c});
        nxt[b].push_back({a,c});
    }
    priority_queue<pair<int,int> > pq;
    pq.push({0,1});
    int ans=0;
    while(!pq.empty()){
        auto tmp = pq.top();
        pq.pop();
        int now = tmp.second;int mut = -tmp.first;
        if(!visit[now]){
            visit[now] = 1;
            ans += node[now]*mut;
            //cout<<ans<<'\n';
        }else continue;
        for(auto i : nxt[now]){
            int t = i.first,now_mut = i.second;
            if(visit[t]) continue;
            //cout<<ans<<'\n';
            pq.push({-(mut+now_mut),t});
        }
    }
    cout<<ans;
}
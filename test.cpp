#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define pii pair<int, int>
#define pb push_back
#define X first
#define Y second
 
constexpr int MAX_N = 1e5+5;
vector<pii> G1[MAX_N], G2[MAX_N];
 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, a, b, w;
	cin >> n >> m;
	for(int x=0; x<m; x++){
		cin >> a >> b >> w;
		G1[a].pb({b, w});
		G2[b].pb({a, w});
	}
	//dijkstra
	vector<int> dis(n+5, -1), dis2(n+5, -1);
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.push({0, 1});
	while(!pq.empty()){
		auto t = pq.top(); pq.pop();
		int w = t.X;
        if(dis[t.Y] == -1) dis[t.Y] = t.X;
        else continue;
		for(auto a : G1[t.Y]){
            if (dis[a.X] != -1) continue;
			pq.push({w+a.Y, a.X});
 		}
	}
	for(int x=2; x<=n; x++) {
		if(dis[x] != -1) G2[1].pb({x, dis[x]});
	}
	pq.push({0, 1});
	while(!pq.empty()){
		auto t = pq.top(); pq.pop();
        if(dis2[t.Y] == -1) dis2[t.Y] = t.X;
        else continue;
		for(auto a : G2[t.Y]){
            if(dis2[a.X] != -1) continue;
			pq.push({t.X+a.Y, a.X});
 		}
	}
	for(int x=2; x<=n; x++ ) cout << dis2[x] << ' ';
	return 0;
}
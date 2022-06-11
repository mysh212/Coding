// Author : ysh
// 06/10/2022 Fri 18:25:12.78
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<C:\Users\Public\debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

struct cp{
    bool operator() (tuple<int,int,int>a,tuple<int,int,int>b) {
        if(get<0>(a) != get<0>(b)) return get<0>(a)<get<0>(b);
        if(get<1>(a) != get<1>(b)) return get<1>(a)>get<1>(b);
        return 1;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;cin>>a>>b>>c;
    int tmp;
    vector<pair<int,int>>f[a];
    vector<int>g(a);
    for(int i = 1;i<a - 1;i++) {
        cin>>g[i];
    }
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,cp>q;
    for(int i = 0;i<b;i++) {
        int aa,bb,cc;cin>>aa>>bb>>cc;
        f[aa - 1].push_back({bb - 1,cc});
        f[bb - 1].push_back({aa - 1,cc});
        // printf("f[%d - 1].push_back({%d - 1,%d});\n",aa,bb,cc);
    }
    q.emplace(0,c,0);
    // for(auto i : f[0]) cout<<i.first<<" "<<i.second<<"\n";
    bool rr[200][200] = {};
    while(!q.empty()) {
        auto now = q.top();q.pop();
        int t = get<0>(now);
        int l = get<1>(now);
        int d = get<2>(now);
        debug(t,l,d);
        for(auto i : f[d]) {
            if((rr[d][i.first] != 1)) {
                // cout<<1;
                if(i.second <= l) {
                    rr[d][i.first] = 1;
                    q.emplace(t,l - i.second,i.first);
                }
                if(i.second <= c) {
                    rr[d][i.first] = 1;
                    q.emplace(t + g[d],c - i.second,i.first);
                }
            }
        }
        if(d == a - 1) {
            cout<<t;
            while(!q.empty()) {
                auto a = q.top();
                debug(get<0>(a),get<1>(a),get<2>(a));
                q.pop();
            }
            return 0;
        }
    }
    cout<<-1;
    return 0;
}
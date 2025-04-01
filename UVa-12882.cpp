// Author : ysh
// 2024/10/22 Tue 21:32:43
// https://vjudge.net/problem/UVA-12882
// RE
#include<bits/stdc++.h>
using namespace std;
#define int long long

#define x first
#define y second

vector<int>color;
int ff(int x) {
    if(color.at(x) == x) return x;
    return color.at(x) = ff(color.at(x));
}
inline void mg(int a,int b) {
    color.at(ff(a)) = ff(b);
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    vector<pair<pair<int,int>,pair<int,int>>>f;
    map<int,vector<array<int,3>>>l,r;
    vector<int>ans;
    while(cin>>n) {
        {
            f.clear();
            l.clear();
            r.clear();
            ans.clear();
            f.resize(n);
            ans.resize(n);
        }

        for(auto &i : f) cin>>i.x.x>>i.x.y>>i.y.x>>i.y.y;
        for(auto &i : f) i.y.x += i.x.x, i.y.y += i.x.y;

        int t = 0;
        for(auto &i : f) {
            {
                auto found = l.find(i.x.y);
                if(found != l.end()) found->second.push_back({i.x.x,i.y.x,t});
                else l.insert({i.x.y,vector<array<int,3>>{{i.x.x,i.y.x,t}}});
            }
            {
                auto found = l.find(i.y.y);
                if(found != l.end()) found->second.push_back({i.x.x,i.y.x,t});
                else l.insert({i.y.y,vector<array<int,3>>{{i.x.x,i.y.x,t}}});
            }
            {
                auto found = r.find(i.x.x);
                if(found != r.end()) found->second.push_back({i.x.y,i.y.y,t});
                else r.insert({i.x.x,vector<array<int,3>>{{i.x.y,i.y.y,t}}});
            }
            {
                auto found = r.find(i.y.x);
                if(found != r.end()) found->second.push_back({i.x.y,i.y.y,t});
                else r.insert({i.y.x,vector<array<int,3>>{{i.x.y,i.y.y,t}}});
            }
            t++;
        }

        for(auto &i : l) sort(i.second.begin(),i.second.end());
        for(auto &i : r) sort(i.second.begin(),i.second.end());

        color.resize(n);
        iota(color.begin(),color.end(),0);

        for(auto &i : l) {
            int rr = -1,now = -1;
            for(auto &j : i.second) {
                if(j[0] > rr) {
                    rr = j[1];
                    now = j[2];
                }
                if(j[1] > rr) {
                    rr = j[1];
                }
                mg(j[2],now);
            }
        }
        for(auto &i : r) {
            int rr = -1,now = -1;
            for(auto &j : i.second) {
                if(j[0] > rr) {
                    rr = j[1];
                    now = j[2];
                }
                if(j[1] > rr) {
                    rr = j[1];
                }
                mg(j[2],now);
            }
        }

        for(int i = 0;i<n;i++) {
            ans.at(ff(i)) += (f.at(i).y.x - f.at(i).x.x) * (f.at(i).y.y - f.at(i).x.y);
        }

        cout<<*max_element(ans.begin(),ans.end())<<"\n";
    }
    return 0;
}
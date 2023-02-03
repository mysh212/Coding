// Author : ysh
// 01/29/2023 Sun 22:16:15.44
// https://tioj.ck.tp.edu.tw/problems/2195
// TLE / MLE (55%)
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>g(n),down(n);
    {
    map<int,int>m;
    int t = 0;
    for(int &i : g) {
        cin>>i;
        m.insert({i,t++});
    }
    for(int i = 0;i<n;i++) {
        cin>>down.at(i);
        g.at(m.find(down.at(i))->second) = i;
    }
    }
    // for(int &i : g) cerr<<i<<" ";
    // cerr<<"\n";
    vector<vector<int>>mark;
    vector<vector<bool>>disable(n,vector<bool>(n));
    {
    vector<int>v;
    for(int i = 0;i<n;i++) {
        int &now = g.at(i);
        auto found = upper_bound(v.begin(),v.end(),now);
        if(next(found) != v.end() && found != v.end()) for(int &i : mark.at(found - v.begin() + 1)) disable.at(now).at(i) = 1;
        if(found == v.end()) mark.push_back({now}),v.push_back(now);
        else mark.at(found - v.begin()).push_back(now),*found = now;
        // for(int &i : v) cerr<<i<<" ";
        // cerr<<"\n";
    }
    }
    // cerr<<v.size();
    vector<int>ans;
    for(int x = 0,len = mark.size();x < len;x++)
        sort(mark.at(x).begin(),mark.at(x).end(),[&] (int a,int b) {
            return down.at(a) > down.at(b);
        });

    vector<vector<bool>>mk(mark.size(),vector<bool>(n));
    function<bool(int,int)> walk = [&] (int x,int t) {
        // cerr<<down.at(x);
        if(x == mark.size()) return true;
        // if(mk.at(x).at(t)) return false;
        for(int &i : mark.at(x)) {
            if(t != -1 && i < t) continue;
            if((t == -1 ? 1 : !disable.at(t).at(i)) && walk(x + 1,i)) return ans.push_back(down.at(i)),true;
        }
        return mk.at(x).at(t) = 1,false;
    };

    walk(0,0);
    // for(auto &i : mark) {for(int &j : i) cerr<<j<<" "; cerr<<"\n";}
    reverse(ans.begin(),ans.end());
    assert(ans.size() == mark.size());
    for(int &i : ans) cout<<i<<" ";
    cout<<"\n";

    return 0;
}
// Author : ysh
// 01/29/2023 Sun 22:16:15.44
// https://tioj.ck.tp.edu.tw/problems/2195
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n),g(n),down(n);
    map<int,int>m;
    iota(f.begin(),f.end(),0);
    down = f;
    srand(time(NULL));
    random_shuffle(down.begin(),down.end());
    int t = 0;
    for(int &i : f) {
        cout<<i<<" ";
        m.insert({i,t++});
    }
    cout<<"\n";
    for(int i = 0;i<n;i++) {
        cout<<down.at(i)<<" ";
        g.at(m.find(down.at(i))->second) = i;
    }
    cout<<"\n";
    // for(int &i : g) cerr<<i<<" ";
    // cerr<<"\n";
    vector<int>v;
    vector<vector<int>>mark;
    for(int i = 0;i<n;i++) {
        int &now = g.at(i);
        auto found = upper_bound(v.begin(),v.end(),now);
        if(found == v.end()) mark.push_back({now}),v.push_back(now);
        else mark.at(found - v.begin()).push_back(now),*found = now;
    }
    vector<int>ans;
    for(int x = 0,len = v.size();x < len;x++)
        sort(mark.at(x).begin(),mark.at(x).end(),[&] (int a,int b) {
            return down.at(a) > down.at(b);
        });

    vector<vector<int8_t>>mk(v.size(),vector<int8_t>(n,-1));
    function<bool(int,int)> walk = [&] (int x,int t) {
        // cerr<<down.at(x);
        if(x == mark.size()) return true;
        if(mk.at(x).at(t) != -1) return (mk.at(x).at(t) == 1);
        for(int &i : mark.at(x)) {
            if(i < t) continue;
            if(walk(x + 1,i)) return ans.push_back(down.at(i)),mk.at(x).at(t) = 1,true;
        }
        return mk.at(x).at(t) = 0,false;
    };

    walk(0,0);
    // for(auto &i : mark) {for(int &j : i) cerr<<j<<" "; cerr<<"\n";}
    reverse(ans.begin(),ans.end());
    for(int &i : ans) cout<<i<<" ";
    cout<<"\n";

    return 0;
}
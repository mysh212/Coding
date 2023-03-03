// Author : ysh
// 03/02/2023 Thu 13:54:50.85
// https://tioj.ck.tp.edu.tw/problems/2189
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

void ft(int &a,int &b,int &d,int c) {
    if(c > a) {
        swap(b,d);
        swap(a,b);
        swap(c,a);
    } else if(c > b) {
        swap(b,d);
        swap(c,b);
    } else if(c > d) {
        swap(c,d);
    }
    return;
}
pair<int,int> getsec(vector<int>&ans,vector<pair<int,int>>&f) {
    debug(f);
    vector<int>l,r;
    for(auto &i : f) {
        l.push_back(i.first);
        r.push_back(i.second);
        assert(i.first >= i.second);
    }
    sort(l.rbegin(),l.rend());
    sort(r.rbegin(),r.rend());
    l.resize(unique(l.begin(),l.end()) - l.begin());
    r.resize(unique(r.begin(),r.end()) - r.begin());
    if(l.size() > 1) ans.push_back(l.at(0) + l.at(1));
    if(l.size() > 1 && r.size() > 1) {
        ans.push_back(l.at(1) + r.at(0));
        ans.push_back(l.at(0) + r.at(1));
    }
    debug(l,r);
    ans.push_back(l.at(0));
    ans.push_back(r.at(0));
    return make_pair(l.at(0),max(r.at(0),(l.size() > 1 ? l.at(1) : INT_MIN)));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<vector<pair<int,int>>>f(n);
    // vector<int>to(n);
    for(int i = 1;i<n;i++) {
        int a,b,c;cin>>a>>b>>c;
        f.at(a).push_back({b,c});
        f.at(b).push_back({a,c});
    }

    vector<int>ans;
    function<pair<int,int>(int,int,int)> check = [&] (int last,int x,int v) {
        vector<pair<int,int>>rec;
        for(auto &i : f.at(x)) {
            if(i.first == last) continue;
            auto tmp = check(x,i.first,i.second);
            debug(i.first,tmp);
            rec.push_back(make_pair(tmp.first + i.second,tmp.second + i.second));
        }
        if(rec.empty()) return make_pair(0,-v);
        return getsec(ans,rec);
    };
    
    check(-1,0,0);
    sort(ans.begin(),ans.end());
    ans.resize(unique(ans.begin(),ans.end()) - ans.begin());
    debug(ans);
    if(ans.size() < 2) {
        cout<<ans.at(0);
    }
    cout<<ans.at(ans.size() - 2);
    return 0;
}
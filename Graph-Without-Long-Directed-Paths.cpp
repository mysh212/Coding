// Author : ysh
// 10/12/2022 Wed 14:01:07.25
// https://codeforces.com/contest/1144/problem/F
#include<bits/stdc++.h>
using namespace std;
vector<int>c;
inline int ff(int x) {
    if(c.at(x) == x) return x;
    return c.at(x) = ff(c.at(x));
}
inline void mg(int a,int b) {
    c.at(ff(a)) = ff(b);
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    c.resize(a);
    iota(c.begin(),c.end(),0);
    vector<vector<int>>f(a);
    vector<pair<int,int>>s;
    for(int i = 0;i<b;i++) {
        int a,b;cin>>a>>b;
        a--;b--;
        f.at(a).push_back(b);
        f.at(b).push_back(a);
        s.push_back(make_pair(a,b));
    }
    vector<bool>mark(a);
    bool bk = 0;
    function<bool(int,int)> check = [&] (int x,int last) {
        if(last != -1 && ff(x) == ff(last)) bk = 1;
        if(bk) return 1;
        if(mark.at(x)) return 0;
        mark.at(x) = 1;
        for(int &i : f.at(x)) {
            if(last != -1) mg(last,i);
            if(check(i,x)) return 1;
        }
        return 0;
    };
    for(int i = 0;i<a;i++) {
        if(!mark.at(i)) check(i,-1);
    }
    if(bk) {
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    int tmp = ff(0);
    for(auto &i : s) {
        cout<<(int) (ff(i.second) == tmp);
    }
    return 0;
}
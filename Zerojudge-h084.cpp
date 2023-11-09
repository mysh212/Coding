// Author : ysh
// 2023/09/26 Tue 17:55:45
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>f(a);
    for(int &i : f) cin>>i;

    multiset<int,greater<int>>s;
    while(b--) {
        int tmp;cin>>tmp;
        s.insert(tmp);
    }

    function<bool(int)> check = [&] (int x) {
        int now = 0;
        vector<int>mark;
        for(int &i : f) {
            if(i >= x) now++;     
            else if(now != 0) mark.push_back(now),now = 0;
        }
        if(now != 0) mark.push_back(now);
        multiset<int,greater<int>>t(s.begin(),s.end());
        for(int &i : mark) {
            while(i > 0) {
                auto found = t.lower_bound(i);
                if(found != t.end()) {
                    i = i - *found;
                    t.erase(found);
                    assert(i >= 0);
                } else {
                    break;
                }
            }
        }
        return t.empty();
    };

    function<int(int,int)> ck = [&] (int l,int r) {
        if(l + 1 == r) return l;
        int mid = (l + r) >> 1;
        if(check(mid)) return ck(mid,r);
        return ck(l,mid);
    };

    cout<<ck(0,int(1e9) + 1);
}
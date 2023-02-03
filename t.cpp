// Author : ysh
// 02/03/2023 Fri 13:18:37.53
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...);
#endif

vector<int>f;
vector<int>& check(string a) {
    f.resize(a.size());
    for(int i = 1,len = a.size();i<len;i++) {
        int p = f[i - 1];
        while(a[p] != a[i] && p != 0) p = f[p - 1];
        if(a[p] == a[i]) f[i] = p + 1;
    }
    return f;
}
vector<int>v;
vector<int>& ck(string a) {
    v.resize(a.size());
    for(int i = 2,len = a.size();i<len;i++) {
        int p = f[i - 2];
        while(a[p + 1] != a[i] && p != 0) p = f[p - 1];
        if(a[p + 1] == a[i]) v[i] = p + 2;
    }
    return v;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a,b;cin>>a>>b;
    auto v = check(b + " " + a);
    auto vv = ck(b + " " + a);
    debug(v);
    debug(vv);
    int ans = 0;
    vector<int>aans;
    for(int i = b.size() + 1,len = v.size();i<len;i++) {
        if(v.at(i) == b.size() - 1 && len != v.size() - 1) ans++,aans.push_back(i - ((b.size() << 1) - 2));
        if(v.at(i) == b.size()) ans++,aans.push_back(i - ((b.size() << 1) - 1));
    }
    for(int i = b.size() + 1,len = v.size();i<len;i++) {
        if(vv.at(i) == b.size()) ans++,aans.push_back(i - ((b.size() << 1) - 1));
    }
    sort(aans.begin(),aans.end());
    aans.resize(unique(aans.begin(),aans.end()) - aans.begin());
    cout<<aans.size()<<"\n";
    for(int &i : aans) {
        cout<<i<<" ";
    }
    return 0;
}
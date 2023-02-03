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
vector<int> check(string a) {
    f.resize(a.size());
    for(int i = 1,len = a.size();i<len;i++) {
        int p = f[i - 1];
        while(a[p] != a[i] && p != 0) p = f[p - 1];
        if(a[p] == a[i]) f[i] = p + 1;
    }
    return f;
}
int r;
vector<int>v;
vector<int> ck(string a) {
    v.resize(a.size());
    v = f;
    for(int i = 2,len = a.size();i<len;i++) {
        int p = f[i - 2] + 1;
        while(a[p] != a[i] && p != 0) p = f[p - 1];
        if(a[p] == a[i]) v[i] = p + 1;
    }
    return v;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a,b;cin>>a>>b;
    r = b.size();
    auto v = check(b + " " + a);
    auto vv = ck(b + " " + a);
    f = vv;
    auto vvv = check(b + " " + a);
    debug(v);
    debug(vv);
    debug(vvv);
    int ans = 0;
    vector<int>aans;
    for(int i = r + 1,len = v.size();i<len;i++) {
        if(v.at(i) == r - 1 && i != v.size() - 1 && (i - ((r << 1) - 2)) > 0) ans++,aans.push_back(i - ((r << 1) - 2));
        if(v.at(i) == r && (i - ((r << 1) - 1)) > 0) ans++,aans.push_back(i - ((r << 1) - 1));
    }
    for(int i = r + 1,len = v.size();i<len;i++) {
        debug(aans,(i - ((r << 1) - 1)));
        if(vv.at(i) == r && ((i - ((r << 1) - 1)) > 0)) ans++,aans.push_back(i - ((r << 1) - 1));
    }
    for(int i = r + 1,len = v.size();i<len;i++) {
        // if(vvv.at(i) == r - 1 && i != vvv.size() - 1 && (i - ((r << 1) - 2)) > 0) ans++,aans.push_back(i - ((r << 1) - 2));
        if(vvv.at(i) == r && (i - ((r << 1) - 1)) > 0) ans++,aans.push_back(i - ((r << 1) - 1));
    }
    sort(aans.begin(),aans.end());
    aans.resize(unique(aans.begin(),aans.end()) - aans.begin());
    cout<<aans.size()<<"\n";
    for(int &i : aans) {
        cout<<i<<" ";
    }
    return 0;
}
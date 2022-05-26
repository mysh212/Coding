// Author : ysh
// 05/21/2022 Sat 17:23:38.31
#include<bits/stdc++.h>
using namespace std;
vector<int>f;
const int MAX = 201;
int a;
map<pair<int,int>,int>mark;
int check(int,int);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int b;cin>>a>>b;
    f.resize(a);
    for(int i = 0;i<a;i++) {
        cin>>f[i];
    }
    cout<<check(0,b);
    return 0;
}
int check(int l,int r) {
    int now = upper_bound(f.begin(),f.end(),l) - f.begin();
    int mmin = INT_MAX;
    bool c = 0;
    for(int i = now;;i++) {
        if(f[i] >= r||a == i) break;
        c = 1;
        int mid = f[i];
        int ll,rr;
        auto found = mark.find({l,mid});
        if(found != mark.end()) ll = found->second;
        else ll = check(l,mid);
        found = mark.find({mid,r});
        if(found != mark.end()) rr = found->second;
        else rr = check(mid,r);
        mmin = min(mmin,ll + rr);
    }
    //printf("(%d,%d) ==> %d\n",l,r,(c ? mmin + (r - l) : 0));
    if(!c) return 0;
    mmin = mmin + (r - l);
    mark.insert({{l,r},mmin});
    return mmin;
}
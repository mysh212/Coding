// Author : ysh
// 2023/07/11 Tue 11:23:09
// https://csacademy.com/contest/archive/task/build-the-fence/
#include<bits/stdc++.h>
using namespace std;
int a,b;
bool check(vector<int>&f,int x) {
    int ans = 0,last = 0;
    for(int i = 0,len = f.size();i<len;i++) {
        if(f.at(i) >= x) last += (f.at(i) / x);
        else ans = max(ans,last),last = 0;
    }
    ans = max(ans,last);
    // cerr<<x<<" "<<ans<<"\n";
    return ans >= b;
}
int ck(int l,int r,vector<int>&f) {
    if(l + 1 == r) return l;
    int mid = (l + r) >> 1;
    if(check(f,mid)) return ck(mid,r,f);
    return ck(l,mid,f);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>a>>b;
    vector<int>f(a);
    for(int &i : f) {
        cin>>i;
    }

    cout<<ck(0,int(1e9) + 1,f);
    return 0;
}
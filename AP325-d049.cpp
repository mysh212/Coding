// Author : ysh
// 07/21/2022 Thu 21:44:18.71
#include<bits/stdc++.h>
using namespace std;
vector<int>f;
int a,b;
// vector<int>mark;
int check(int n) {
    // if(mark[n] != -1) return mark[n];
    int l = -1;
    int ans = 0;
    for(int i = 0;i<a;i++) {
        if(l >= f[i]) continue;
        l = f[i] + n;
        ans++;
    }
    if(l < f[a - 1]) ans++;
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>a>>b;
    f.resize(a);
    // mark.resize(a,-1);
    for(int &i : f) {
        cin>>i;
    }
    sort(f.begin(),f.end());
    int l,r;
    l = 0;r = f[a - 1];
    // int ans = 0;
    while(l != r) {
        int mid = (l + r) >> 1;
        int now = check(mid);
        // cerr<<"check("<<mid<<") = "<<now<<"\n";
        if(now > b) {
            l = mid + 1;
        }
        if(now < b) {
            r = mid - 1;
        }
        if(now == b) {
            r = mid;
        }
    }
    cout<<l;
    return 0;
}
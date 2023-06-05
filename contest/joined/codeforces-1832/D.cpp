// Author : ysh
// 05/12/2023 Fri 23:26:17.68
#include<bits/stdc++.h>
using namespace std;
#define int long long
bool check(vector<int>&f,int x,int k) {
    int n = f.size();
    int r = 0;
    if(k <= n) {
        vector<int>g = f;
        for(int &i : g) {
            i = i + (k--);
            if(k == 0) break;
        }
        return *min_element(g.begin(),g.end()) >= x;
    }
    if(not (n & 1) == (k & 1)) {
        for(int i = 0;i<n - 1;i++) {
            if(x - f.at(i) > k) return 0;
            else r = r + (k - (x - f.at(i))),k--;
        }
        if(f.at(n - 1) < x) return 0;
        else r = r + (f.at(n - 1) - x);
        return ((r << 1) >= k);
    }
    for(int i = 0;i<n;i++) {
        if(x - f.at(i) > k) return 0;
        else r = r + (k - (x - f.at(i))),k--;
    }
    return ((r << 1) >= k);
}
int ck(vector<int>&f,int l,int r,int k) {
    if(l + 1 == r) return l;
    int mid = (l + r) >> 1;
    if(check(f,mid,k)) return ck(f,mid,r,k);
    return ck(f,l,mid,k);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    if(a == 1) {
        int c;cin>>c;
        while(b--) {
            int b;cin>>b;
            cout<<c - (b >> 1) + (b & 1 ? b : 0)<<" ";
        }
        return 0;
    }
    vector<int>f(a);
    for(int &i : f) {
        cin>>i;
    }
    sort(f.begin(),f.end());

    while(b--) {
        int b;cin>>b;
        vector<int>g = f;
        cout<<ck(g,0,(int) 2e9 + 1,b)<<" ";
    }
    return 0;
}
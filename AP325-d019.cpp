// Author : ysh
// 07/15/2022 Fri 19:13:53
#include<bits/stdc++.h>
using namespace std;
#define int long long
int k = 0;
vector<int>f;
vector<int> check(int l,int r) {
    // printf("%d %d\n",l,r);
    if(l == r) {
        return {vector<int>({0,f[l]})};
    }
    if(l > r) return vector<int>({0});
    int mid = (l + r) >> 1;
    vector<int>ll(check(l,mid));
    vector<int>rr(check(mid + 1,r));
    vector<int>o;
    for(int i : ll) {
        for(int j : rr) {
            if(i + j <= k) {
                o.push_back(i + j);
            } 
        }
    }
    // printf("%d\n",o.size());
    // for(int i : o) {
    //     printf("%d ",i);
    // }
    // printf("\n");
    return o;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    for(int i = 0;i<a;i++) {
        int tmp;cin>>tmp;
        // tmp = tmp % b;
        f.push_back(tmp);
    }
    k = b;
    // int ans = 0;
    vector<int>ll(check(0,(a >> 1)));
    vector<int>rr(check((a >> 1) + 1,a - 1));
    set<int>m(rr.begin(),rr.end());
    int mmax = 0;
    for(int i = 0,len = ll.size();i < len;i++) {
        auto found = m.lower_bound(b - ll[i]);
        found  = prev(found);
        if(found != m.begin()) {
            mmax = max(mmax,*found + ll[i]);
        }
    }
    cout<<mmax;
    return 0;
}

// Author : ysh
// 07/15/2022 Fri 15:15:25
#include<bits/stdc++.h>
using namespace std;
#define int long long
int k = 0;
vector<int>f;
vector<int> check(int l,int r) {
    // printf("%d %d\n",l,r);
    if(l == r) {
        return {vector<int>({1,f[l]})};
    }
    if(l > r) return vector<int>({1});
    int mid = (l + r) >> 1;
    vector<int>ll(check(l,mid));
    vector<int>rr(check(mid + 1,r));
    vector<int>o;
    for(int i : ll) {
        for(int j : rr) {
            o.push_back(i * j % k);
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
        tmp = tmp % b;
        f.push_back(tmp);
    }
    k = b;
    int ans = 0;
    vector<int>ll(check(0,a >> 1));
    vector<int>rr(check((a >> 1) + 1,a - 1));
    for(int i : ll) {
        for(int j : rr) {
            if(i * j % b == 1) ans++;
        }
    }
    cout<<ans - 1;
    return 0;
}

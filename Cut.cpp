// Author : ysh
// 06/06/2022 Mon 10:54:01.62
// https://192.168.193.20/contest/2/problem/038
#include<bits/stdc++.h>
using namespace std;
vector<int>f;
vector<int>v(3);
int a,b,c;
int check(int);
#ifdef LOCAL
#else
#define printf(...) '*'
#endif
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    for(int &i : v) {
        cin>>i;
    }
    // sort(v.begin(),v.end());
    f.resize(n + 1,-1);
    cout<<check(n);
    return 0;
}
int check(int x) {
    if(x == 0) return 0;
    // vector<int> t(1,INT_MIN);
    int mmax = INT_MIN;
    for(int i = 0;i<3;i++) {
        if(v[i] <= x) {
            if(f[x - v[i]] == -1) {
                // t.push_back(check(x - v[i]));
                f[x - v[i]] = check(x - v[i]);
                mmax = max(mmax,f[x - v[i]]);
            } else {
                // printf("t.push_back(f[%d] = %d);\n",x - v[i],f[x - v[i]]);
                // t.push_back(f[x - v[i]]);
                mmax = max(mmax,f[x - v[i]]);
            }
            // mmax = max(mmax,t.back());
        }
    }
    // printf("%d ==> %d\n",x,mmax);
    return mmax + 1;
}
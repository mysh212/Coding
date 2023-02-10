// Author : ysh
// 06/08/2022 Wed 15:36:47.97
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    map<int,int>l,r;
    for(int i = 0;i<n;i++) {
        int tmp;cin>>tmp;
        l[tmp] = i;
    }
    for(int i = 0;i<n;i++) {
        int tmp;cin>>tmp;
        r[tmp] = i;
    }
    int tmp;
    int ll,rr;ll = rr = 0;
    while(cin>>tmp) {
        if(ll > l[tmp] || rr > r[tmp]) return -1;
        else ll = l[tmp],rr = r[tmp];
    }
    return 0;
}
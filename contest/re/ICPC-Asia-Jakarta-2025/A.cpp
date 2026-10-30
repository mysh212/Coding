// Author : ysh
// 2026/10/29 Thu 16:39:41
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int g = arr[0];
    for(int i=1;i<n;i++) g = gcd(g,arr[i]);
    if(g > 1) cout<<1<<'\n'<<g<<' '<<1;
    else cout<<2<<'\n'<<4<<' '<<2<<'\n'<<2<<' '<<1;
}
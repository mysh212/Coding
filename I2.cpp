// Author : ysh
// 04/18/2022 Mon 12:54:53.27
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;cin>>n>>m;
    vector<pair<int,int>>f(n);
    int tmp;
    for(int i = 0;i<n;i++) {
        cin>>f[i].first>>f[i].second>>f[i].second>>tmp;
    }
    vector<int>a(1000005);
    for(int i = 0;i<n;i++) {
        int x = f[i].first;
        int y = f[i].second;
        a[x]++;
        a[y + 1]--;
    }
    int count = 0;
    for(int i = 0;i<=1000005;i++) {
        count += a[i];
        a[i] = count;
    }
    for(int i = 0;i<m;i++) {
        cin>>tmp;
        cout<<a[tmp]<<" \n"[i == m - 1];
    }
    return 0;
}
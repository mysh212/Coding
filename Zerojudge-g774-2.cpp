// Author : ysh
// 03/19/2022 Sat 18:23:18.20
#include<bits/stdc++.h>
using namespace std;
int c[2005][2005] = {};
pair<int,int> d[4001] = {};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    int n = a+b;
    int tmpa,tmpb;
    for(int i = 0;i<n;i++) {
        cin>>tmpa>>tmpb;
        d[i] = {tmpa,tmpb};
    }
    int hold = 0;
    for(int i = 1;i<=a;i++) {
        c[i][0] = hold + d[i - 1].first;
        hold = hold + d[i - 1].first;
    }
    hold = 0;
    for(int i = 1;i<=b;i++) {
        c[0][i] = hold + d[i - 1].second;
        hold = hold + d[i - 1].second;
    }
    for(int i = 1;i<=a;i++) {
        for(int j = 1;j<=b;j++) {
            c[i][j] = min(c[i - 1][j] + d[i + j - 1].first,c[i][j - 1] + d[i + j - 1].second);
        }
    }
    cout<<c[a][b];
    // for(int i = 0;i<=a;i++) {
    //     for(int j = 0;j<=b;j++) {
    //         cout<<c[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    return 0;
}
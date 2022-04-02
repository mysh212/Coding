// Author : ysh
// 03/19/2022 Sat 18:43:07.83
#include<bits/stdc++.h>
using namespace std;
pair<int,int> d[4001] = {};
int c[2005] = {};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    int tmpa,tmpb;
    for(int i = 0;i<a+b;i++) {
        cin>>tmpa>>tmpb;
        d[i] = {tmpa,tmpb};
    }
    for(int i = 1;i<=b;i++) {
        c[i] = c[i - 1] + d[i - 1].second;
    }
    // for(int i = 0;i<=b;i++) {
    //     cout<<c[i]<<" ";
    // }
    // cout<<"\n";
    for(int i = 1;i<=a;i++) {
        for(int j = 0;j<=b;j++) {
            if(j == 0) {
                c[j] = c[j] + d[i - 1].first;
                continue;
            }
            c[j] = min(c[j - 1] + d[i + j - 1].second,c[j] + d[i + j - 1].first);
        }
    // for(int i = 0;i<=b;i++) {
    //     cout<<c[i]<<" ";
    // }
    // cout<<"\n";
    }
    cout<<c[b];
    return 0;
}
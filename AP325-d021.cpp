// Author : ysh
// 07/15/2022 Fri 22:50:36
#include<bits/stdc++.h>
using namespace std;
int k;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>k;
    int a,b;cin>>a>>b;
    int c[a + 1][b] = {};
    for(int i = 1;i<=a;i++) {
        for(int j = 0;j<b;j++) {
            cin>>c[i][j];
            c[i][j] = c[i - 1][j] + c[i][j];
        }
    }
    int mmax = 0;
    for(int i = 1;i<=a;i++) {
        for(int j = i;j<=a;j++) {
            int last = 0;
            set<int>s({0});
            for(int k = 0;k<b;k++) {
                last += c[j][k] - c[i - 1][k];
                auto found = s.lower_bound(last - ::k);
                if(found != s.end()) {
                    mmax = max(mmax,last - *found);
                }
                s.insert(last);
            }
        }
    }
    cout<<mmax;
    return 0;
}

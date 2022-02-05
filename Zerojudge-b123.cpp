#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a,b;
    while(cin>>a>>b) {
    int r[a][b];
    int l[b] = {0};
    int ll[b] = {0};
    int mmax = 0;
    for(int i = 0;i<a;i++) {
        for(int j = 0;j<b;j++) {
            cin>>r[i][j];
            l[j] = (r[i][j] == 1 ? l[j] + 1:0);
        }
        for(int k = 0;k<b;k++) {
            ll[k] = l[k];
            for(int j = k+1;j<b;j++) {
                ll[j] = min(ll[j - 1],l[j]);
                mmax = max(mmax,(j - k + 1) * ll[j]);
            }
        }
    }
    cout<<mmax<<"\n";
    }
}
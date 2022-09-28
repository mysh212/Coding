#include<bits/stdc++.h>
using namespace std;
int a,b;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    int last = 0;
    int mmin = 0;
    for(int i = 0;i<n;i++) {
        int tmp;cin>>tmp;
        tmp = last += tmp;
        mmin = min(mmin,tmp);
    }
    cout<<-mmin;
    return 0;
}

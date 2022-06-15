// Author : ysh
// 06/14/2022 Tue  8:50:34.93
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        string a[3];
        for(string &i : a) {
            cin>>i;
        }
        string mmax = "";
        int smax = 0;
        for(int i = 0;i<=2;i++) {
            if(a[i].size() < smax) continue;
            if(smax == a[i].size()) mmax = max(mmax,a[i]);
            else mmax = a[i];
            smax = a[i].size();
        }
        cout<<mmax<<"\n";
    }
    return 0;
}
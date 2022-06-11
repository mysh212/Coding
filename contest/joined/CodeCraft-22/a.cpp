// Author : ysh
// 06/01/2022 Wed  8:29:51.41
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m;cin>>m;
    while(m--) {
        int n;cin>>n;
        int a[2] = {};
        int tmp;
        while(n--) {
            cin>>tmp;
            a[tmp & 1]++;
        }
        cout<<min(a[0],a[1])<<"\n";
    }
    return 0;
}
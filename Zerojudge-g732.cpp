// Author : ysh
// 09/30/2022 Fri 13:55:51.91
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int f[500] = {};
    int n;cin>>n;
    int tmp;
    for(int i = 0;i<n;i++) {
        cin>>tmp;
        f[tmp - 1]++;
    }
    int l = 0;
    for(int i = 0;i<=(n >> 1);i++) {
        while(1) {
            if(f[l] != 0) {
                f[l]--;
                break;
            }
            l++;
        }
    }
    cout<<l + 1;
    return 0;
}
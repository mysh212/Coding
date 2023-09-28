// Author : ysh
// 05/28/2023 Sun 22:48:36.70
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        for(int i = 0;i<n;i++) {
            int tmp;cin>>tmp;
            cout<<(n + 1) - tmp<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
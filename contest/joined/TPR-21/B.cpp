// Author : ysh
// 05/29/2022 Sun 15:13:27.30
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    if(a > b) {
        swap(a,b);
    }
    // cout<<(b - a == 1 ? -1 : b - a);
    // return 0;
    if(a == 0 && b == 0) {
        cout<<-1;
        return 0;
    }
    if(a == 0) {
        cout<<b;
        return 0;
    }
    for(int i = 2;i<b;i++) {
        if(a % i == b % i) {
            cout<<i;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}
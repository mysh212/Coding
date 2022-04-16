// Author : ysh
// 04/06/2022 Wed 22:49:04.35
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int a,b;cin>>a>>b;
        int c[a*b] = {};
        for(int &i : c) {
            cin>>i;
        }
        int m = a * b;
        bool d = 0;
        for(int i = 0;i + i<m;i++) {
            if(c[i] != c[m - 1 - i]) {
                d = 1;
                cout<<"keep defending\n";
                break;
            }
        }
        if(!d) cout<<"go forward\n";
    }
    return 0;
}
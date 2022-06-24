// Author : ysh
// 06/22/2022 Wed 17:42:23.45
#include<bits/stdc++.h>
using namespace std;
int c[100][100];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;
    while(cin>>a>>b) {
        for(int i = 0;i<a;i++) {
            for(int j = 0;j<b;j++) {
                cin>>c[i][j];
            }
        }
        for(int i = 0;i<b;i++) {
            for(int j = 0;j<a;j++) {
                cout<<c[j][i]<<" \n"[j == a - 1];
            }
        }
    }
    return 0;
}
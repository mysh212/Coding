// Author : ysh
// 04/22/2022 Fri 20:49:33.55
#include<bits/stdc++.h>
using namespace std;
int c[501][501] = {};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a,b;cin>>a>>b;
    int lena = a.size(),lenb = b.size();
    for(int i = 1;i<=lena;i++) {
        char now = a.at(i - 1);
        for(int j = 1;j<=lenb;j++) {
            if(now != b.at(j - 1)) c[i][j] = max(c[i - 1][j],c[i][j - 1]);
            else c[i][j] = c[i - 1][j - 1] + 1;
        }
    }
    cout<<c[lena][lenb];
    return 0;
}
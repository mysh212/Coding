// Author : ysh
// 10/31/2022 Mon 21:19:32.91
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a,b;
    while(cin>>a>>b) {
        int aa = a.size();
        int bb = b.size();
        vector<vector<int>>c(aa + 1,vector<int>(bb + 1));
        // int c[aa + 1][bb + 1] = {};
        for(int i = 1;i<=aa;i++) {
            for(int j = 1;j<=bb;j++) {
                if(a.at(i - 1) == b.at(j - 1)) c[i][j] = c[i - 1][j - 1] + 1;
                else c[i][j] = max(c[i - 1][j],c[i][j - 1]);
            }
        }
        cout<<c[aa][bb]<<"\n";
    }
    return 0;
}
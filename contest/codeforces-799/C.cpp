// Author : ysh
// 06/14/2022 Tue 22:47:22.55
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int c[8][8] = {};
        const int n = 8;
        // bool d = 0;
        for(int i = 0;i<n;i++) {
            string a;cin>>a;
            for(int j = 0;j<n;j++) {
                if(a.at(j) == '#') {
                    c[i][j] = 1;
                    if(i >= 1 && j >= 1 && j <= 6) {
                        if(c[i - 1][j - 1] == 1 && c[i - 1][j + 1] == 1) {
                            // d = 1;
                            cout<<i + 1<<" "<<j + 1<<"\n";
                            // break;
                        }
                    }
                }
            }
            // if(d) break;
        }
    }
    return 0;
}
// Author : ysh
// 06/30/2022 Thu 12:28:04.25
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int r = 1;
    while(cin>>n) {
        int m;m = n;
        if(m == 0) {
            return 0;
        }
        vector<int>f(m);
        int sig = 0;
        for(int i = 0;i<m;i++) {
            cin>>f[i];
            sig += f[i];
        }
        sig = sig / m;
        int ans = 0;
        for(int i = 0;i<m;i++) {
            ans = ans + max(f[i] - sig,0);
        }
        cout<<"Set #"<<r++<<"\nThe minimum number of moves is ";
        cout<<ans<<".\n\n";
    }
    return 0;
}
// Author : ysh
// 2023/07/07 Fri 22:41:44
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        string a,b,c;cin>>a>>b>>c;
        bool o = 0;
        for(int i = 0;i<=2;i++) {
            if(o) continue;
            if(a[i] == b[i] && b[i] == c[i] && a[i] != '.') cout<<a[i]<<"\n",o = 1;
        }
        if(!o && a[0] == a[1] && a[1] == a[2] && a[0] != '.') cout<<a[0]<<"\n",o = 1;
        if(!o && b[0] == b[1] && b[1] == b[2] && b[0] != '.') cout<<b[0]<<"\n",o = 1;
        if(!o && c[0] == c[1] && c[1] == c[2] && c[0] != '.') cout<<c[0]<<"\n",o = 1;
        if(!o && a[0] == b[1] && b[1] == c[2] && a[0] != '.') cout<<a[0]<<"\n",o = 1;
        if(!o && c[0] == b[1] && b[1] == a[2] && c[0] != '.') cout<<c[0]<<"\n",o = 1;
        if(!o) cout<<"DRAW\n";
    }
    return 0;
}
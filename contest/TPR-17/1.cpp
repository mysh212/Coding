// Author : ysh
// 04/02/2022 Sat 14:11:36.74
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;cin>>a>>b>>c;string aa,bb,cc;
    if(a + b == 2) cin>>aa>>bb;
    else cin>>aa>>bb>>cc; 
    int tmp;
    while(c--) {
        cin>>tmp;
        tmp = tmp % 4;
        if(a == 1&&b == 2) {
            if(tmp & 1) cout<<aa;
            if(tmp == 2) cout<<bb;
            if(tmp == 0) cout<<cc;
        }
        if(a == 2&&b == 1) {
            if(!(tmp & 1)) cout<<cc;
            if(tmp == 1) cout<<aa;
            if(tmp == 3) cout<<bb;
        }
        if(a == 1&&b == 1) {
            tmp = tmp % 2;
            if(tmp == 1) cout<<aa;
            else cout<<bb;
        }
        cout<<"\n";
    }
    return 0;
}
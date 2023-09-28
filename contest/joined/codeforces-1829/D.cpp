// Author : ysh
// 05/06/2023 Sat 23:07:56.91
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int a,b;cin>>a>>b;
        int tmp = __gcd(a,b);
        a = a / tmp;
        b = b / tmp;
        int aa,bb;aa = bb = 0;
        bool c = 0;
        while(a != 1) {
            if(a % 3 != 0) {
                c = 1;
                break;
            }
            a = a / 3;
            aa++;
        }
        while(b != 1) {
            if(b % 2 != 0) {
                c = 1;
                break;
            }
            b = b >> 1;
            bb++;
        }
        if(aa >= bb && !c) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
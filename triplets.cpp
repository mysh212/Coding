// Author : ysh
// 02/03/2022 Thu 13:28:31.38
// http://choj.me/problem/00076
// TLE(1100ms,11MB)
#include<bits/stdc++.h>
using namespace std;
unsigned long long a = 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int tmp;cin>>tmp;
        int n = tmp;
        //cout<<((a>>(n - 1)) & 1)<<"\n";
        if(((a>>(n - 1)) & 1) == 1) a = a - (1 << (n - 1));
        //(a >> n) << n | (a | ((1 << (n - 1)) - 1))
        else a = a | (1 << (n - 1));
        //cout<<a<<"\t";
    }
    //cout<<a;
    n = 1;
    while(1) {
        //cout<<a<<"\t";
        if(a & 1 == 1) {
            cout<<n;
            return 0;
        }
        a >>= 1;
        n++;
    }
}
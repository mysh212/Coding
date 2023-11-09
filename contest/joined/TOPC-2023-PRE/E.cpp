// Author : ysh
// 2023/09/16 Sat 09:51:43
#include<bits/stdc++.h>
using namespace std;
int r = 0;
int a,b;
int fp(int a,int b) {
    if(b == 1) return a;
    int tmp = check(a,b >> 1);
    tmp = (tmp * tmp - 2;

    if(b & 1) return tmp * a % r;
    return tmp % r;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    
}
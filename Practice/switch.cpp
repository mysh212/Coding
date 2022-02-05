// Author : ysh
// 01/08/2022 Sat 20:37:06.86
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    printf("%d\n",n);
    switch (n) {
    case 1:
        cout<<10;
        break;
    case 1+1:
        cout<<20;
        break;
    default:
        n=99;
    }
    return 0;


}
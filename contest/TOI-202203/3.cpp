// Author : ysh
// 04/01/2022 Fri 18:43:05.75
#include<bits/stdc++.h>
using namespace std;
void check(int a,int b) {
    // printf("%d",a);
    int tmp = b % (1 << (a - 1));
    if(tmp == 0) cout<<a<<"\n";
    else check(a - 1,tmp);
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    int a,b;
    while(n--) {
        cin>>a>>b;
        check(a,b);
    }
    return 0;
}
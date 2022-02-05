// Author : ysh
// 01/21/2022 Fri  9:15:07.34
#include<bits/stdc++.h>
using namespace std;
int n,m;
bool c = 0;
void check(int* a,int n,bool t,int tmp,int* f,int now) {
    if(t == 1) {
        tmp += a[n];
        f[now] = a[n];
        now++;
    }
    if(n == ::n - 1) {
        if(tmp == m) {
            c = 1;
            for(int i = 0;i<now;i++)  {
                cout<<f[i]<<" ";
            }
            cout<<"\n";
        }
        return;
    }
    if(tmp > m) return;
    check(a,n+1,1,tmp,f,now);
    check(a,n+1,0,tmp,f,now);
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    int a[n] = {},b[n] = {};
    for(int i = 0;i<n;i++) {
        cin>>a[i];
    }
    sort(a,a+n);
    check(a,0,1,0,b,0);
    check(a,0,0,0,b,0);
    if(c == 0) cout<<"-1\n";
    return 0;
}
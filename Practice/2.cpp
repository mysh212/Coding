// Author : ysh
// 01/08/2022 Sat 21:12:36.58
#include<bits/stdc++.h>
using namespace std;
void pc(int*,int);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    int a[n] = {};
    for(int i = 0;i<n;i++) {
        cin>>a[i];
    }
    int b,c;cin>>b>>c;
    int d[n+1] = {};
    for(int i = 0;i<n;i++) {
        d[i+1] = d[i] + a[i];
    }
    pc(a,n);
    pc(d,n+1);
}
void pc(int* c,int n) {
    for(int i = 0;i<n;i++) {
        cout<<c[i]<<" ";
    }
    cout<<"\n";
    return;
}
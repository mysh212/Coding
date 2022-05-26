// Author : ysh
// 04/26/2022 Tue 22:10:59.11
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    
    int a,b;cin>>a>>b;
    int c[b] = {};
    int d[b] = {};
    int k[b] = {};
    int r[b] = {};
    int* p = c;
    int* n = d;
    for(int j = 0;j<a;j++) {
        for(int i = 0;i<b;i++) {
            cin>>k[i];
            if(j >= 1 && i >= 1) n[i] = max(p[i],n[i - 1]) + k[i];
            else if(j >= 1) n[i] = p[i] + k[i];
            else if(i >= 1) n[i] = max(k[i],n[i - 1] + k[i]);
            else n[i] = k[i];
        }
        for(int i = b - 1;i>=0;i--) {
            if(j >= 1 && i < b - 1) r[i] = max(p[i],r[i + 1]) + k[i];
            else if(j >= 1) r[i] = p[i] + k[i];
            else if(i < b - 1) r[i] = max(k[i],r[i + 1] + k[i]);
            else r[i] = k[i];
            n[i] = max(n[i],r[i]);
        }
        swap(p,n);
    }
    /*
    for(int i = 0;i<a;i++) {
        for(int j = 0;j<b;j++) {
            cout<<c[i][j]<<" ";
        }
        cout<<"\n";
    }
    */
   int mmax = INT_MIN;
   for(int i = 0;i<b;i++) {
       mmax = max(mmax,p[i]);
   }
    cout<<mmax;
    return 0;
}
// Author : ysh
// 01/08/2022 Sat  9:21:56.51
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    int a[n] = {};
    for(int i = 0;i<n;i++) {
        cin>>a[i];
    }
    for(int i = 0;i<(n>>1)+1;i++) {
        for(int j = n - 1;j>i;j++) {
            if(a[j]<a[j - 1]) swap(a[j],a[j - 1]);
        }
    }
    /*
    int k = 0;
    int tmp = ;
    int c[n] = {};
    for(int i = 0;i<n;i++) {
        if(a[i] == tmp) continue;
        c[k] = a[i];
        tmp = a[i];
        k++;
    }
    */
    cout<<a[n/2];
}
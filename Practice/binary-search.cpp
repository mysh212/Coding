// Author : ysh
// 03/23/2022 Wed  9:15:40.42
#include<bits/stdc++.h>
using namespace std;
int check(int* a,int l,int r,int f) {
    //printf("%d %d",l,r);
    int mid = (l + r) >> 1;
    if(a[mid] == f) return mid;
    if(!(l < r)) return -1;
    if(a[mid] < f) return check(a,mid + 1,r,f);
    if(a[mid] > f) return check(a,l,mid - 1,f);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;cin>>n>>m;
    int a[n] = {};
    for(int &i : a) {
        cin>>i;
    }
    sort(a,a+n);
    int tmp;
    while(m--) {
        cin>>tmp;
        cout<<check(a,0,n - 1,tmp)<<"\n";
    }
    return 0;
}
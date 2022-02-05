// Author : ysh
// 02/04/2022 Fri 16:51:00.94
// http://choj.me/problem/00121
#include<bits/stdc++.h>
using namespace std;
bool a[1000][1000] = {};
int ans = 0;
void check(int x,int n,int l,int now) {
    if(now <= l) ans++;
    else return;
    for(int i = 0;i<x;i++) {
        if(a[i][x]) {
            a[i][x] = 0;
            check(i,n,l,now+1);
        }
    }
    for(int i = x+1;i<n;i++) {
        if(a[x][i]) {
            a[x][i] = 0;
            check(i,n,l,now+1);
        }
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    for(int i = 1;i<n;i++) {
        int tmpa,tmpb;cin>>tmpa>>tmpb;
        if(tmpa>tmpb) swap(tmpa,tmpb);
        a[tmpa][tmpb] = 1;
    }
    int me,l;cin>>me>>l;
    check(me,n,l,1);
    cout<<n - ans;
    return 0;
}
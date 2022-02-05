// Author : ysh
// 02/01/2022 Tue  8:41:16.69
// https://open.kattis.com/problems/walrusweights
#include<bits/stdc++.h>
using namespace std;
void check(int*,int,int);
int n,ans = 0,mans=1000;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    int c[n] = {};
    for(int &i : c) {
        cin>>i;
    }
    sort(c,c+n);
    check(c,0,0);
    cout<<ans;
    return 0;
}
void check(int* c,int now,int sig) {
    if((mans<abs(sig-1000))&&(sig>1000)) return;
    if(now == n - 1) {
        int plus=sig+c[now];
        int tmp;
        if(abs(1000-sig)>=abs(1000-plus)) tmp = plus;
        else tmp = sig;
        int mtmp = abs(1000-tmp);
        if(mans==mtmp) {
            ans = max(ans,tmp);
            mans = abs(1000-ans);
        } else if(mans>mtmp) {
            ans = tmp;
            mans = abs(1000-tmp);
        }
        return;
    }
    check(c,now+1,sig+c[now]);
    check(c,now+1,sig);
    return;
}
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a,b;cin>>a>>b;
    int f[a] = {};
    int p[a] = {};
    for(int i = 0;i<a;i++) {
        cin>>f[i];
    }
    for(int i = 0;i<a;i++) {
        cin>>p[i];
    }
    int ans,mmax,tmp;ans=mmax=tmp=0;
    for(int i = 0;i<a;i++) {
        if(p[i] != tmp) {
            ans += mmax;
            mmax = 0;
            tmp = p[i];
        }
        mmax = max(mmax,f[i]);
    }
    ans += mmax;
    //cout<<"\n";
    cout<<ans;
    return 0;
}
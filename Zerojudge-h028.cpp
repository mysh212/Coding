// Author : ysh
// 03/06/2022 Sun 11:32:31.40
#include<bits/stdc++.h>
using namespace std;
struct box{
    box* left;
    box* right;
    int tree = 0;
    int h = 0;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;cin>>n>>m;
    box b[n+2];
    b[0].left = &b[0];
    b[0].right = &b[1];
    b[0].tree = 0;
    b[0].h = m+1;
    b[n+1].left = &b[n];
    b[n+1].right = &b[n+1];
    b[n+1].tree = m;
    b[n+1].h = m+1;
    for(int i = 1;i<=n;i++) {
        b[i].left = &b[i - 1];
        b[i].right = &b[i + 1];
        cin>>b[i].tree;
    }
    for(int i = 1;i<=n;i++) {
        cin>>b[i].h;
    }
    int mmax,ans;mmax=ans=0;
    auto i = &b[1];
    while(1) {
        if(i == &b[n+1]) break;
        if(i == 0) i = b[0].right;
        if(i->tree - i->h >= i->left->tree||i->tree + i->h <= i->right->tree) {
            i->left->right = i->right;
            i->right->left = i->left;
            mmax = max(mmax,i->h);
            ans++;
        } else {
            i = i->right;
            continue;
        }
        i = i->left;
    }
    cout<<ans<<"\n"<<mmax;
    return 0;
}
// Author : ysh
// 07/22/2022 Fri 17:13:52
#include<bits/stdc++.h>
using namespace std;
struct box{
    int l,r;
    box(int l = 0,int r = 0):
        l(l), r(r) {};
};
vector<box>mark;
vector<bool>f;
// vector<bool>re;
int a,b;
int c = 0;
int d = 0;
inline void flip(int n) {
    if(f[n]) {
        f[n] = 0;
        c--;
    } else {
        f[n] = 1;
        c++;
    }
    return;
}
pair<int,vector<int>> check() {
    // for(int i : f) cout<<i<<" ";
    // cout<<c<<"\n";
    // printf("%d\n",d);
    if(c == 0) return {1,{}};
    if(d == b - 1) return {0,{}};
    // for(int i = d++;i<b;i++) {
        auto light = mark[d++];
        flip(light.l);flip(light.r);
        auto now = check();
        flip(light.l);flip(light.r);
        if(now.first) {
            now.second.push_back(--d);
            return {1,{now.second}};
        }
        now = check();
        if(now.first) {
            // now.second.push_back(--d);
            d--;
            return {1,{now.second}};
        }
        d--;
        return {0,{}};
    // }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>a>>b;
    f.resize(a);
    mark.resize(b);
    // re.resize(b);
    for(int i = 0;i<a;i++) {
        int tmp;cin>>tmp;
        if(tmp) {
            f[i] = 1;
            c++;
        }
    }
    for(int i = 0;i<b;i++) {
        cin>>mark[i].l>>mark[i].r;
        mark[i].l--;
        mark[i].r--;
    }
    auto now = check();
    if(now.first) {
        cout<<"Yes\n"<<now.second.size()<<"\n";
        for(int i = now.second.size() - 1;i >= 0;i--) {
            cout<<now.second.at(i) + 1<<"\n";
        }
    } else {
        cout<<"No\n";
    }
    return 0;
}

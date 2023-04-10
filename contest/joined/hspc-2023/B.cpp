// Author : ysh
// 04/09/2023 Sun 16:07:47.39
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

struct box{
    int a,b,c;
    box(int a = 0,int b = 0,int c = 0):
        a(a), b(b), c(c) {};
    bool operator<(box &x) {
        return c < x.c;
    }
};
vector<int>color;
int ff(int x) {
    if(color.at(x) == x || color.at(x) == -1) return x;
    return color.at(x) = ff(color.at(x));
}
void mg(int a,int b) {
    color.at(ff(a)) = ff(b);
    return;
}
int check(vector<box>&f,int a,int b) {
    color.resize(a << 1,-1);
    for(auto &i : f) {
        if(ff(i.a) == ff(i.b)) return i.c;
        mg(i.a,i.b + a);mg(i.b,i.a + a);
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<box>f(b);
    for(auto &i : f) {
        cin>>i.a>>i.b>>i.c;
        i.a--;i.b--;
    }
    sort(f.rbegin(),f.rend());
    cout<<check(f,a,b);
    return 0;
}

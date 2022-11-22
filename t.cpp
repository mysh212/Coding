// Author : ysh
// 11/22/2022 Tue 23:10:35.62
#include<bits/stdc++.h>
using namespace std;
#include<seg_tree>
struct box{
    int x = 0;
    box(int x = 0):
        x(x) {};
    inline box operator+(box a) {
        return box(max(x,a.x));
    }
    inline box operator+=(box a) {
        return x = x + a.x;
    }
    inline box operator*(int a) {
        return box(x * a);
    }
};
box operator-(int a,box b) {
    return box(a - b.x);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,b;cin>>n>>b;
    vector<box>f(n);
    for(box &i : f) {
        cin>>i.x;
    }
    seg_tree<box>t(f);
    while(b--) {
        int a,b,c;cin>>a>>b>>c;
        if(a == 1) {
            b--;
            t.add(b,b,box(c - f.at(b)));
            f.at(b) = c;
            continue;
        }
        b--;c--;
        cout<<t.sum(b,c).x<<"\n";
    }
    return 0;
}
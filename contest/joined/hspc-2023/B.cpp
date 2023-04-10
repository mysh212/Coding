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
    debug(a,b);
    color.at(ff(a)) = ff(b);
    return;
}
vector<int>mark;
bool ms(int a,int b) {
    a = ff(a);b = ff(b);
    if(mark.at(a) == -1 && mark.at(b) == -1) return mark.at(b) = a,mark.at(a) = ff(b),1;
    if(mark.at(a) == -1) return mg(a,mark.at(b)),mark.at(a) = ff(b),1;
    if(mark.at(b) == -1) return mg(b,mark.at(a)),mark.at(b) = ff(a),1;
    if(ff(mark.at(b)) == ff(a) || ff(mark.at(a)) == ff(b) || ff(mark.at(a)) == ff(mark.at(b)) || ff(a) == ff(b)) return 0;
    mg(a,mark.at(b));mg(b,mark.at(a));
    return 1;
}
int check(vector<box>&f,int a,int b) {
    color = vector<int>(a,-1);
    mark = vector<int>(a,-1);
    for(int i = 0;i<b;i++) {
        if(!ms(f.at(i).a,f.at(i).b)) return f.at(i).c;
        debug(f.at(i).a,f.at(i).b);
        debug(color);
        debug(mark);
        // cerr<<"\n";
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
    // for(auto i : f) {
    //     cout<<i.a<<" "<<i.b<<" "<<i.c<<"\n";
    // }
    cout<<check(f,a,b);
    return 0;
}
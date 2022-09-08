// Author : ysh
// 09/08/2022 Thu  9:07:26.81
#include<bits/stdc++.h>
using namespace std;
vector<int>f;
int a,b;
inline int pr(int a) {
    int tmp = a >> 1;
    tmp = tmp << 1;
    if(tmp == a) {
        return a + 1;
    }
    return tmp;
}
vector<bool>mark;
inline int ff(int x,bool t = 0) {
    if(!t) mark = vector<bool>(a);
    if(mark.at(x)) return f.at(x) = x;
    mark.at(x) = 1;
    if(f.at(x) == x || f.at(x) == -1) return x;
    return f.at(x) = ff(f.at(x),true);
}
inline void mg(int a,int b) {
    f.at(ff(a)) = pr(b);
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>a>>b;
    f.resize(a + 1,-1);
    // iota(f.begin(),f.end(),0);
    for(int i = 0;i<b;i++) {
        int a,b;cin>>a>>b;
        mg(a,b);
    }
    vector<int>bkp = f;
    int c,d;cin>>c>>d;
    for(int i = 1;i<=c;i++) {
        bool o = 0;
        for(int j = 0;j<d;j++) {
            int a,b;cin>>a>>b;
            if(o) continue;
            int aa = ff(a);
            int bb = ff(b);
            if(aa == bb) {
                cout<<i<<"\n";
                f = bkp;
                o = 1;
            }
            mg(aa,bb);
        }
    }
    return 0;
}
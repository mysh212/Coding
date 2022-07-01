// Author : ysh
// 06/30/2022 Thu 21:55:37.35
#include<bits/stdc++.h>
using namespace std;
struct box{
    int a;
    int b;
    box(int a,int b):
        a(a), b(b) {};
    bool operator<(box b) {
        return a < b.a;
    }
};
inline bool cp(box a,box b) {
    return a.a < b.a;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<box>f(2,box(1,3));
    f[1].a = 2;
    sort(f.begin(),f.end(),cp);
    cout<<(int) (f[0] < f[1])<<"\n";
    for(box i : f) {
        cout<<i.a<<" ";
    }
    return 0;
}
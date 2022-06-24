// Author : ysh
// 06/15/2022 Wed 11:36:01.98
#include<bits/stdc++.h>
using namespace std;
class box{
    public:
    int a,b;
    void check() {
        cout<<a<<" "<<b<<"\n";
    }
    bool operator<(box c) {
        if(a != c.a) return a < c.a;
        return b < c.b;
    }
    explicit box(int a = 0,int b = 0):
        a(a), b(b) {};
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<box>f(n);
    for(box &i : f) {
        int a,b;cin>>a>>b;
        i = box(a,b);
    }
    function<void()> a = [] () {
        cout<<"ok";
    };
    a();
    sort(f.begin(),f.end(),[] (box a,box b) {
        return a.b < b.b;
    });
    for(box &i : f) {
        i.check();
    }
    return 0;
}
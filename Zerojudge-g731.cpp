// Author : ysh
// 10/03/2022 Mon 14:45:05.73
#include<bits/stdc++.h>
using namespace std;
#define int long long
struct box{
    int x,y;
    box(int x = 0,int y = 0):
        x(x), y(y) {};
    box operator+(box r) {
        int nx = x * r.y + r.x * y;
        int ny = y * r.y;
        int d = __gcd(nx,ny);
        return box(nx / d,ny / d);
    }
};
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a;cin>>a;
    vector<box>f;
    function<void()> output = [&] () {
        cout<<'=';
        for(int i = 0,len = f.size();i<len;i++) {
            if(i != 0) cout<<'+';
            int now = len - i - 1;
            cout<<f.at(now).x<<'/'<<f.at(now).y;
        }
        cout<<"\n";
    };
    bool c = 0;
    int nn = 0;
    int tmp = 0;
    for(int i = 0,len = a.size();i<len;i++) {
        char now = a.at(i);
        if(now == '/') {
            c = 1;
            continue;
        }
        if(now == '+') {
            c = 0;
            // int d = __gcd(tmp,nn);
            f.push_back(box(tmp,nn));
            tmp = 0;
            nn = 0;
            continue;
        }
        if(!c) {
            tmp = (tmp * 10) + (now - '0');
        }
        if(c) {
            nn = (nn * 10) + (now - '0');
        }
    }
    // int d = __gcd(tmp,nn);
    f.push_back(box(tmp,nn));
    // for(box i : f) {
    //     cout<<i.x<<" "<<i.y<<"\n";
    // }
    reverse(f.begin(),f.end());
    while(f.size() > 1) {
        box a = f.back();f.pop_back();
        box b = f.back();f.pop_back();
        f.push_back(a + b);
        output();
    }
    return 0;
}
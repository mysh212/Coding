// Author : ysh
// 11/06/2022 Sun 11:46:01.20
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

struct box{
    int x = 0;char y = '0';int z = 0;
    box(int x = 0,char y = '0',int z = 0):
        x(x), y(y), z(z) {};
    inline bool operator<(const box a) const {
        if(z != a.z) return z < a.z;
        if(y != a.y) return y < a.y;
        return x < a.x;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    map<int,string>m;
    int b = 0;
    for(int i = 0;i<5;i++) {
        string a;cin>>a;
        m.insert({i,a});
        if(a == "buy?") b = i;
    }
    // vector<vector<int>>m;
    map<box,int>p;
    for(int i = 0;i<n;i++) {
        vector<char>f;
        for(int j = 0;j<5;j++) {
            char t;cin>>t;
            f.push_back(t);
        }
        bool buy = f.at(b) == 'Y';
        for(int j = 0;j<5;j++) p[box(j,f.at(j),buy)]++;
    }
    function<double(int,char)> check = [&] (int x,char k) {
        // int n = 0;
        vector<int>f;
        int n = 0,y = 0;
        auto found = p.find(box(x,k,1))->second;
        auto ffound = p.find(box(x,k,0))->second;
        n = found + ffound;
        debug(found,ffound,n);
        debug((((found * found * 1.0 / (n * n)) + (ffound * ffound * 1.0 / (n * n)))));
        return 1 - (((found * found * 1.0 / (n * n)) + (ffound * ffound * 1.0 / (n * n))));
    };
    function<int(int,char)> amount = [&] (int x,char k) {
        return p.find(box(x,k,1))->second + p.find(box(x,k,0))->second;
    };
    vector<double>mark(5);
    // cerr<<amount(0,'H');
    for(auto i : p) {
        mark.at(i.first.x) += amount(i.first.x,i.first.y) * check(i.first.x,i.first.y) / n / 2;
    }
    // for(auto i : p) cout<<i.first.x<<" "<<i.first.y<<" "<<i.first.z<<"\n";
    double mmin = mark.at((b == 0 ? 1 : 0));
    int k = 0;
    for(int i = 0;i<5;i++) {
        if(i == b) continue;
        mmin = min(mark.at(i),mmin);
        if(mark.at(i) < mmin) {
            mmin = mark.at(i);
            k = i;
        }
    }
    cout<<m[k]<<"\n"<<fixed<<setprecision(3)<<mmin;
    // debug(mark);
}
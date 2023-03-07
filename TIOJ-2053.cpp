// Author : ysh
// 03/04/2023 Sat 18:56:57.26
// https://tioj.ck.tp.edu.tw/problems/2053
#include<bits/stdc++.h>
using namespace std;
#define R 1000000007
#define int long long
struct square{
    vector<vector<int>>f;
    int a,b;

    square(int a,int b) {
        this->a = a;
        this->b = b;
        f.resize(a,vector<int>(b));
    }

    square(vector<vector<int>>v) {
        a = v.size();
        b = v.at(0).size();
        f = v;
    }

    square operator*(square &c) {
        assert(f.at(0).size() == c.f.size());
        square tmp(a,c.b);
        for(int i = 0;i<a;i++) {
            for(int j = 0;j<c.b;j++) {
                for(int k = 0;k<b;k++) {
                    tmp.f.at(i).at(j) += f.at(i).at(k) * c.f.at(k).at(j);
                    tmp.f.at(i).at(j) = tmp.f.at(i).at(j) % R;
                }
            }
        }
        return tmp;
    }

    square operator^(int x) {
        if(x == 1) return *this;
        square tmp = (*this) ^ (x >> 1);
        if(x & 1) return tmp * tmp * (*this);
        return tmp * tmp;
    }
};
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c,d,e;cin>>a>>b>>c>>d>>e;
    square ans(vector<vector<int>>({{a},{b}}));
    square f(vector<vector<int>>({{0,1},{c,d}}));
    f = f ^ (e - 1);
    cout<<(f * ans).f.at(0).at(0);
    return 0;
}
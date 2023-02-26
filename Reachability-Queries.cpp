// Author : ysh
// 02/25/2023 Sat 21:28:57.77
// https://cses.fi/problemset/task/2143
// TLE
#include<bits/stdc++.h>
using namespace std;
struct square{
    vector<vector<bool>>mark;
    int n;

    square(int n) {
        this->n = n;
        mark.resize(n,vector<bool>(n));
        for(int i = 0;i<n;i++) {
            mark[i][i] = 1;
        }
    }

    square operator*(square &a) {
        square tmp(a.n);
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                tmp.mark[i][j] = tmp.mark[i][j] | mark[i][j] | a.mark[i][j];
                if(tmp.mark[i][j]) continue;
                for(int k = 0;k<n;k++) {
                    if(mark[i][k] && mark[k][j]) {
                        tmp.mark[i][j] = 1;
                        continue;
                    }
                }
            }
        }
        return tmp;
    }

    square operator^(int a) {
        if(a == 1) return *this;
        square tmp = (*this) ^ (a >> 1);
        if(a & 1) return tmp * tmp * (*this);
        return tmp * tmp;
    }

    void print() {
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                cerr<<((int) mark[i][j])<<" ";
            }
            cerr<<"\n";
        }
        return;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;cin>>a>>b>>c;
    square f(a);
    for(int i = 0;i<b;i++) {
        int a,b;cin>>a>>b;
        f.mark[a - 1][b - 1] = 1;
    }

    // f.print();
    f = f ^ a;
    // f.print();
    for(int i = 0;i<c;i++) {
        int a,b;cin>>a>>b;
        cout<<(f.mark[a - 1][b - 1] ? "YES\n" : "NO\n");
    }
    return 0;
}
// Author : ysh
// 09/15/2022 Thu 20:13:04.26
// https://atcoder.jp/contests/dp/tasks/dp_r
#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int R = 1e9 + 7;
struct box{
    vector<vector<int>>f;
    box(vector<vector<int>>&v) {
        f = move(v);
    }

    box(int n) {
        f.resize(n,vector<int>(n));
    }
    
    inline box operator*(box x) {
        int n = x.f.size();
        box tmp = box(n);
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                for(int k = 0;k < n;k++) {
                    tmp.f.at(i).at(j) += f.at(i).at(k) * x.f.at(k).at(j);
                    tmp.f.at(i).at(j) = tmp.f.at(i).at(j) % R;
                    // [2][3] ==> [2][0] * [0][3] + [2][1] * [1][3] + ...
                }
            }
        }
        return tmp;
    }

    inline void input(int n) {
        f.resize(n,vector<int>(n));
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                cin>>f.at(i).at(j);
            }
        }
        return;
    }

    inline void print() {
        int n = f.size();
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                cout<<f.at(i).at(j)<<" ";
            }
            cout<<"\n";
        }
        return;
    }

    inline box operator^(int k) {
        if(k == 1) return *this;
        box t = *this ^ (k >> 1);
        t = t * t;
        if(k & 1) {
            t = t * *this;
        }
        return t;
    }
};
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,r;cin>>n>>r;
    box t = box(0);
    t.input(n);
    t = t ^ r;
    int ans = 0;
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n;j++) {
            ans = ans + t.f.at(i).at(j);
            ans = ans % R;
        }
    }
    cout<<ans;
    return 0;
}
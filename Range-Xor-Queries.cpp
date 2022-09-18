// Author : ysh
// 09/18/2022 Sun  9:12:35.91
// https://cses.fi/problemset/task/1650
#include<bits/stdc++.h>
using namespace std;
#define int long long
struct tree{
    vector<int>f;
    int n;

    tree(vector<int> &v) {
        this->n = v.size();
        f.resize(v.size());
        int t = 0;
        for(int &i : v) {
            add(t++,i);
        }
    }

    void add(int a,int b) {
        for(;a < n;a = a | (a + 1)) { 
            f.at(a) = f.at(a) ^ b;
        }
        return;
    }

    int sum(int a) {
        int ans = 0;
        for(;a >= 0;a = (a & (a + 1)) - 1) {
            ans = ans ^ f.at(a);
        }
        return ans;
    }

    int sum(int l,int r) {
        return sum(max(l,r)) ^ sum(min(l,r) - 1);
    }
};
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>f(a);
    for(int &i : f) {
        cin>>i;
    }
    tree t(f);
    while(b--) {
        int a,b;cin>>a>>b;
        cout<<t.sum(a - 1,b - 1)<<"\n";
    }
    return 0;
}
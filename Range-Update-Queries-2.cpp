// Author : ysh
// 08/18/2022 Thu 20:50:48.09
// https://cses.fi/problemset/hack/1651/list/
#include<bits/stdc++.h>
using namespace std;
#define int long long
struct tree{
    vector<int>f;
    int n;

    tree(int n) {
        this->n = n;
        f.resize(n);
    }

    tree(vector<int>&v):
    tree(v.size()) {
        int t = 0;
        for(int i : v) add(t++,i);
    }

    void add(int a,int b) {
        for(;a < n;a = a | (a + 1)) {
            f[a] += b;
        }
    }

    int sum(int a) {
        int ans = 0;
        for(;a >= 0;a = (a & (a + 1)) - 1) {
            ans = ans + f[a];
        }
        return ans;
    }
};
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>f(a + 1);
    int last = 0;
    for(int i = 0;i<a;i++) {
        cin>>f[i];
        int tmp = f[i];
        f[i] = f[i] - last;
        last = tmp;
    }
    tree t = tree(f);
    for(int i = 0;i<b;i++) {
        int tmp;cin>>tmp;
        if(tmp == 1) {
            int aa,bb,c;cin>>aa>>bb>>c;
            t.add(aa - 1,c);
            t.add(bb,-c);
        }
        if(tmp == 2) {
            int r;cin>>r;
            cout<<t.sum(r - 1)<<"\n";
        }
    }
    return 0;
}
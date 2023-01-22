// Author : ysh
// 01/20/2023 Fri 15:06:44.79
#include<bits/stdc++.h>
using namespace std;
template<typename T>
struct tree{
    std::vector<T>f;
    T n;

    tree(T n) {
        this->n = n;
        f.resize(n);
    }

    tree(std::vector<T>&v):
    tree(v.size()) {
        T t = 0;
        for(T i : v) add(t++,i);
    }

    void add(T a,T b) {
        for(;a < n;a = a | (a + 1)) {
            f[a] = max(f[a],b);
        }
    }

    T sum(T a) {
        T ans = 0;
        for(;a >= 0;a = (a & (a + 1)) - 1) {
            ans = max(ans,f[a]);
        }
        return ans;
    }

    T sum(T a,T b) {
        if(a > b) std::swap(a,b);
        return sum((std::min(n - 1,b))) - sum(a - 1);
    }
};
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n),g(n);
    int mmax = 0;
    for(int &i : f) {
        cin>>i;
        mmax = max(mmax,i);
    }
    for(int &j : g) {
        cin>>j;
    }
    vector<int>v(mmax + 1);
    tree<int>t(mmax + 1);
    for(int i = 0;i<n;i++) {
        int tmp = t.sum(f.at(i) - 1) + g.at(i);
        if(tmp > v.at(f.at(i))) {
            t.add(f.at(i),tmp);
            v.at(f.at(i)) = tmp;
        }
    }
    cout<<t.sum(mmax);
    return 0;
}
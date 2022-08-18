// Author : ysh
// 08/17/2022 Wed 22:00:02.29
#include<bits/stdc++.h>
using namespace std;
#define int long long

struct tree {
    vector<int> bit;  // binary indexed tree
    int n;

    tree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    tree(vector<int> a) : tree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int>f,g;
    int n;cin>>n;
    map<int,int>m;
    // priority_queue<pair<int,int>>q;
    for(int i = 0;i<n;i++) {
        int tmp;cin>>tmp;
        f.push_back(tmp);
        m.insert({tmp,0});
        // q.push({tmp,i});
    }
    int ans = 0;
    // sort(g.begin(),g.end());
    // g.resize(unique(g.begin(),g.end()) - g.begin());
    int r = 0;
    for(auto &i : m) {
        i.second = r++;
    }
    tree t = tree(m.size());
    for(int i = n - 1;i >= 0;i--) {
        auto now = f[i];
        int r = m.find(now)->second;
        if(0 <= r - 1) ans = ans + t.sum(0,r - 1);
        t.add(r,1);
    }
    cout<<ans;
    return 0;
}
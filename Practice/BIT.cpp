// Author : ysh
// 08/18/2022 Thu  7:56:50.18
#include<bits/stdc++.h>
using namespace std;

struct tree {
    vector<int>f;
    int n;

    void add(int r,int v) {
        for(;r < n;r = r | (r + 1)) {
            f[r] += v;
            cout<<r<<" ";
        }
    }

    int sum(int r) {
        int ans = 0;
        for(;r >= 0;r = (r & (r + 1)) - 1) {
            ans += f[r];
            cout<<r<<" ";
        }
        return ans;
    }

    int sum(int l,int r) {
        if(l > r) swap(l,r);
        return sum(r) - sum(l - 1);
    }

    tree(int n) {
        this->n = n;
        f.resize(n);
    }

    tree(vector<int>v):
        tree(v.size()) {
        for(int i = 0,len = v.size();i<len;i++) {
            add(i,v[i]);
        }
    };

    void operator+=(pair<int,int>a) {
        add(a.first,a.second);
        return;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    tree t = tree(8);
    for(int i = 0;i<8;i++) {
        cout<<i<<": ";
        t.add(i,1);
        cout<<"\n";
    }
    cout<<"\n";
    for(int i = 0;i<8;i++) {
        cout<<i<<": ";
        t.sum(i);
        cout<<"\n";
    }
    return 0;
}
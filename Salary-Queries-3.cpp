// Author : ysh
// 08/17/2022 Wed 16:59:33.49
// https://cses.fi/problemset/task/1144
#include<bits/stdc++.h>
using namespace std;
map<int,int>m;
struct box{
    bool a;
    int b,c;
    box(char x = ' ',int y = 0,int z = 0) {
        a = (x == '?' ? 1 : 0);
        b = y;
        c = z;
        if(!a) {
            b--;
            m.insert({c,0});
        }
    }
};

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int a,b;cin>>a>>b;
    vector<int>ff(a);
    for(int &i : ff) {
        cin>>i;
        m.insert({i,0});
    }
    queue<box>q;
    for(int i = 0;i<b;i++) {
        char a;cin>>a;
        int b,c;cin>>b>>c;
        q.push(box(a,b,c));
    }
    int r = 0;
    for(auto &i : m) {
        i.second = r++;
    }
    // for(auto &i : m) {
    //     cout<<i.first<<" ";
    // }
    int n = m.size();
    tree t = tree(n);
    // f.resize(n + 1);
    // mt(0,n - 1,&c[t++]);
    for(int i : ff) {
        // pluz(0,n - 1,&c[0],m[i],1);
        t.add(m[i],1);
    }
    while(!q.empty()) {
        auto now = q.front();q.pop();
        bool a = now.a;
        int x,y;x = now.b;y = now.c;
        if(a) {
            // cout<<check(m.lower_bound((x >= 0 ? x : 0))->second,prev(m.upper_bound(y))->second,&c[0])<<"\n";
            cout<<t.sum(m.lower_bound(x)->second,prev(m.upper_bound(y))->second)<<"\n";
            continue;
        }
        // pluz(0,n - 1,&c[0],m[ff.at(x)],-1);
        t.add(m[ff[x]],-1);
        // pluz(0,n - 1,&c[0],m[ff.at(x) = y],1);
        t.add(m[ff[x] = y],1);
    }
    return 0;
}

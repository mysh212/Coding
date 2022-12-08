// Author : ysh
// 12/07/2022 Wed 12:54:30.08
#include<bits/stdc++.h>
using namespace std;
struct tree{
    vector<long long>f;
    int n;

    tree(vector<long long>&f) {
        this->n = f.size();
        this->f.resize(n);
        for(int i = 0,len = f.size();i<len;i++) {
            add(i,f.at(i));
        }
    }

    void add(int a,long long b) {
        for(;a < n;a = (a | (a + 1))) {
            f.at(a) += b;
        }
        return;
    }

    long long sum(int a) {
        long long ans = 0;
        for(;a >= 0;a = (a & (a + 1)) - 1) {
            ans = ans + f.at(a);
        }
        return ans;
    }

    long long sum(int a,int b) {
        if(a > b) swap(a,b);
        return sum(min(n - 1,b)) - sum(a - 1);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<long long>f(n + 1);
    long long last = 0;
    for(int i = 1;i<=n;i++) {
        cin>>f.at(i);
        swap(last,f.at(i));
        f.at(i) = last - f.at(i);
    }
    vector<long long>g(n + 1);
    for(int i = 1;i<=n;i++) {
        g.at(i) = f.at(i) * (i);
    }
    tree a(f),b(g);
    int m;cin>>m;
    while(m--) {
        int aa,bb;cin>>aa>>bb;
        if(aa == 2) {
            int c;cin>>c;
            cout<<(a.sum(1,c) * (c + 1) - b.sum(1,c)) - (a.sum(1,bb - 1) * (bb) - b.sum(1,bb - 1))<<"\n";
        }
        if(aa == 1) {
            int c,d;cin>>c>>d;
            // cout<<(a.sum(1,b - 1) * (c + 1) - b.sum(1,c)) - (a.sum(1,b - 1) * (b) - b.sum(1,b - 1))
            a.add(bb,d);
            if(c != n) a.add(c + 1,-d);
            b.add(bb,d * bb);
            if(c != n) b.add(c + 1,-d * (c + 1));
        }
    }
    return 0;
}
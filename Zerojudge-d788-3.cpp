// Author : ysh
// 09/03/2022 Sat 19:42:36.78
#include<bits/stdc++.h>
using namespace std;
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
        for(int i : f) {
            add(t++,i);
        }
    }

    void add(int a,int b) {
        for(;a < n;a = (a | (a + 1))) {
            f[a] = f[a] + b;
        }
        return;
    }

    int sum(int a) {
        int ans = 0;
        for(;a >= 0;a = (a & (a + 1)) - 1) {
            ans += f[a];
        }
        return ans;
    }

    inline int sum(int a,int b) {
        if(a > b) swap(a,b);
        return sum(b) - sum(a);
    }
}t = tree(0);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while(cin>>n) {
        t = tree(n + 1);
        for(int i = 0;i<n;i++) {
            int tmp;cin>>tmp;
            t.add(tmp,1);
            cout<<t.sum(tmp,n) + 1<<"\n";
        }
    }
    return 0;
}
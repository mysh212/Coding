// Author : ysh
// 2024/01/23 Tue 14:33:39
#include<bits/stdc++.h>
using namespace std;
#define int long long
struct tree{
    vector<int>f;
    int n;

    tree(int n):
        n(n), f(n) {};
    
    tree(vector<int>&v):
        tree(v.size()) {
            int t = 0;
            for(int &i : v) {
                add(t++,i);
            }
            return;
        }

    void add(int a,int b) {
        for(int i = a;i<n;i = i | (i + 1)) {
            f.at(i) += b;
        }
        return;
    }

    int get(int x) {
        int ans = 0;
        for(int i = x;i>=0;i = (i & (i + 1)) - 1) {
            ans = ans + f.at(i);
        }
        return ans;
    }

    int get(int l,int r) {
        assert(0 <= l && l < n && 0 <= r && r < n);
        if(l > r) swap(l,r);
        if(l == 0) return get(r);
        return get(r) - get(l - 1);
    }
};
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n << 1);
    vector<vector<int>>mark(n);
    int r = 0;
    for(int &i : f) cin>>i,i--,mark.at(i).push_back(r++);

    int ans = 0;
    tree t(n << 1);
    for(int i = 0;i<n;i++) {
        assert(mark.at(i).size() == 2);
        ans = ans + t.get(mark.at(i).at(0),mark.at(i).at(1));
        t.add(mark.at(i).at(0),1);
        t.add(mark.at(i).at(1),1);
    }
    cout<<ans;
    return 0;
}
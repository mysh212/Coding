// Author : ysh
// 2023/09/23 Sat 15:39:18
// https://codeforces.com/contest/1430/problem/E
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>t;
    int n;cin>>n;
    string a;cin>>a;
    vector<vector<int>>mark(26);
    {
    int t = 0;
    for(char i : a) {
        mark.at(i - 'a').push_back(t++);
    }
    }
    vector<int>f(n);
    for(auto &i : mark) {
        int m = i.size();
        for(int j = 0;j<m;j++) {
            f.at(i.at(j)) = (n - i.at(m - 1 - j) - 1);
        }
    }

    // for(int &i : f) {
    //     cerr<<i<<" ";
    // }

    long long ans = 0;
    for(int &i : f) {
        // cerr<<i<<" "<<(t.size() - t.order_of_key(*t.lower_bound(i)))<<"\n";
        auto found = t.lower_bound(i);
        if(not (found == t.end())) ans = ans + (t.size() - t.order_of_key(*found));
        t.insert(i);
    }

    cout<<ans;
    return 0;
}
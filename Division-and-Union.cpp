// Author : ysh
// 2023/08/14 Mon 12:56:13
// https://codeforces.com/contest/1101/problem/C
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        // tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>t;
        int n;cin>>n;
        vector<array<int,3>>f(n);
        int t = 0;
        for(auto &i : f) {
            cin>>i[0]>>i[1];
            i[2] = t++;
        }

        sort(f.begin(),f.end());
        int mmax = f.at(0)[1];
        int ans = 0;
        for(auto &i : f) {
            if(i[0] > mmax) {
                break;
            }
            mmax = max(mmax,i[1]);
            ans++;
        }

        if(ans == n) cout<<"-1\n";
        else {
            vector<bool>aans(n);
            int t = 0;
            for(auto &i : f) {
                if(t++ < ans) aans.at(i[2]) = 1;
                else break;
            }

            for(bool i : aans) {
                cout<<(i ? '1' : '2')<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
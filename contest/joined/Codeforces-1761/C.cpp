// Author : ysh
// 11/20/2022 Sun 23:17:41.26
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        vector<vector<int>>f(n);
        vector<bool>in(n),c(n);
        vector<int>to(n);
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                char tmp;cin>>tmp;
                if(tmp == '1') {
                    c.at(j) = 1;
                    c.at(i) = 1;
                    in.at(i) = 1;
                    f.at(j).push_back(i);
                    to.at(i)++;
                }
            }
        }
        int r = 0;
        // for(int i : to) cout<<i<<" ";
        for(int i = 0;i<n;i++) {
            if(!c.at(i) || !in.at(i)) r++;
        }
        // cout<<r;
        vector<vector<bool>>ans(n,vector<bool>(n));
        vector<bool>now(n),mark(n);
        function<void(int,int,int)> check = [&] (int last,int x,int level) {
            if(last != -1) now.at(x) = 1;
            if(last == -1 && r != 1) now.at(x) = 1;
            if(to.at(x) >= level) now.at(x) = 0;
            for(int i = 0;i < n;i++) if(now.at(i)) ans.at(x).at(i) = 1;
            if(last != -1) now.at(x) = 1;
            for(int &i : f.at(x)) {
                if(i != last) check(x,i,level + 1);
            }
            now.at(x) = 0;
            return;
        };
        // for(int i : in) cout<<i;
        for(int i = 0;i<n;i++) {
            if(!in.at(i)) {
                check(-1,i,1);
            }
        }
        // for(auto i : ans) {
        //     for(int j : i) {
        //         cout<<j;
        //     }
        //     cout<<"\n";
        // }
        for(int i = 0;i<n;i++) {
            int c = n;
            for(int j = 0;j<n;j++) {
                // if(r != 1 && i == j) {
                //     c--;
                //     continue;
                // }
                if(ans.at(i).at(j)) c--;
            }
            cout<<c<<" ";
            for(int j = 0;j<n;j++) {
                // if(r != 1 && i == j) continue;
                if(!ans.at(i).at(j)) cout<<j + 1<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
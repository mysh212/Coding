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
        // vector<bool>in(n),c(n);
        vector<bool>to(n);
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                char tmp;cin>>tmp;
                if(tmp == '1') {
                    f.at(i).push_back(j);
                    to.at(j) = 1;
                }
            }
        }
        vector<vector<bool>>ans(n,vector<bool>(n));
        for(int i = 0;i<n;i++) ans[i][i] = 1;
        vector<int>now;
        function<void(int,int)> check = [&] (int last,int x) {
            now.push_back(x);
            for(int &i : now) ans.at(x).at(i) = 1;
            for(int &i : f.at(x)) {
                if(i != last) check(x,i);
            }
            now.pop_back();
            return;
        };
        for(int i = 0;i<n;i++) {
            if(to.at(i) == 0) check(-1,i);
        }
        for(int i = 0;i<n;i++) {
            vector<int>tmp;
            int c = 0;
            for(int j = 0;j<n;j++) {
                if(ans.at(i).at(j)) {
                    c++;
                    tmp.push_back(j);
                }
            }
            cout<<c<<" ";
            for(int i : tmp) {
                cout<<i<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
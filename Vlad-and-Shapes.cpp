// Author : ysh
// 2024/02/20 Tue 08:37:07
// https://codeforces.com/contest/1926/problem/B
#include<bits/stdc++.h>
using namespace std;
const int xx[] = {0,1,0,-1};
const int yy[] = {1,0,-1,0};
#include<slow>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        vector<vector<int>>f(n,vector<int>(n));
        for(auto &i : f) for(int &j : i) {
            char tmp;cin>>tmp;
            j = (tmp == '1');
        }
        
        vc<int>ans;
        repo(&i,f) {
            int tmp = 0;
            repo(&j,i) if(j == 1) tmp++;
            ans.pb(tmp);
        }

        sort(all(ans));
        ans.resize(unique(all(ans)) - ans.begin());

        if(ans.size() <= 2) cout<<"SQUARE";
        else cout<<"TRIANGLE";
        cout<<"\n";
    }
    return 0;
}
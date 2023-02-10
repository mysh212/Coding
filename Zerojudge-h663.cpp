// Author : ysh
// 01/26/2023 Thu 13:34:15.02
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<vector<int>>f(n,vector<int>(n));
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n;j++) {
            cin>>f.at(i).at(j);
        }
    }
    vector<vector<int>>mark(n + 1,vector<int>(1 << n));
    vector<vector<pair<int,int>>>mk(n + 1,vector<pair<int,int>>(1 << n));
    function<int(int,int,int)> check = [&] (int last,int x,int now) {
        if(x == n) return 0;
        if(last != -1 && mark.at(last).at(now) != 0) return mark.at(last).at(now);
        int ans = INT_MAX;int d = 0;int nnow = 0;
        for(int i = 0;i<n;i++) {
            if(now & (1 << i)) continue;
            int tmp = now | (1 << i);
            int r = check(i,x + 1,tmp) + (last != -1 ? f.at(last).at(i) : 0);
            if(r < ans) {
                ans = r;
                d = i;
                nnow = tmp;
            }
        }
        if(last != -1) mk.at(last).at(now) = {d,nnow};
        else mk.at(n).at(now) = {d,nnow};
        if(last == -1) return ans;
        return mark.at(last).at(now) = ans;
    };
    cout<<check(-1,0,0)<<"\n";
    vector<int>ans;
    int x = n,y = 0;
    while(ans.size() != n) {
        int nx = mk.at(x).at(y).first;
        int ny = mk.at(x).at(y).second;
        x = nx;y = ny;
        ans.push_back(x + 1);
    }
    for(int &i : ans) cout<<i<<" ";
    return 0;
}
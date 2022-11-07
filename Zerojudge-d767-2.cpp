// Author : ysh
// 11/04/2022 Fri  8:28:42.40
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

vector<vector<int>>mark;
vector<int>dp;
int n,g;
void ck(int,int,int,int,vector<vector<int>>&);
void init(int n,int root,vector<vector<int>>&f) {
    int g = __lg(n);
    mark.resize(n,vector<int>(g + 1));
    dp.resize(n);
    ck(n,g,root,root,f);
}
void ck(int n,int g,int r,int last,vector<vector<int>>&f) {
    debug(last + 1,r + 1);
    mark[r][0] = last;
    dp[r] = dp[last] + 1;
    for(int i = 1;i<=g;i++) {
        mark[r][i] = mark[mark[r][i - 1]][i - 1];
    }
    for(int &i : f.at(r)) {
        if(i != last) ck(n,g,i,r,f);
    }
    return;
}
int check(int a,int b) {
    if(dp.at(a) > dp.at(b)) swap(a,b);
    int jump = dp.at(b) - dp.at(a);
    for(int i = 0;jump < n && i <= g;i++,jump = jump >> 1) {
        if(jump & 1) b = mark[b][i];
    }
    if(a == b) return a;
    for(int i = g;i >= 0;i--) {
        if(mark[a][i] == mark[b][i]) continue;
        a = mark[a][i];
        b = mark[b][i];
    }
    return mark[a][0];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    n = a;g = __lg(a);
    vector<vector<int>>f(a);
    vector<bool>in(a);
    for(int i = 0;i<a;i++) {
        int tmp;
        while(cin>>tmp) {
            if(tmp == 0) break;
            tmp--;
            f.at(i).push_back(tmp);
            in.at(tmp) = 1;
        }
    }
    debug(f);
    int root = -1;
    for(int i = 0;i<a;i++) {
        if(!in.at(i)) {
            root = i;
            break;
        }
    }
    init(a,root,f);
//    for(auto i : mark) {
//        for(int &j : i) {
//            cout<<j<<" ";
//        }
//        cout<<"\n";
//    }
    while(b--) {
        int a,b;cin>>a>>b;
        a--;b--;
        int ans = check(a,b);
        cout<<ans + 1<<" "<<dp.at(a) + dp.at(b) - (dp.at(ans) << 1)<<"\n";
    }
    return 0;
}

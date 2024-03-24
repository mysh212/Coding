// Author : ysh
// 2024/01/20 Sat 16:04:58
// https://cses.fi/problemset/task/2134
// NF
#include<bits/stdc++.h>
using namespace std;
int a,b;
vector<vector<int>> init(vector<vector<int>>&f,int n) {
    int g = __lg(n) + 1;
    vector<vector<int>>ans(n,vector<int>(g));
    queue<pair<int,int>>q;
    q.emplace(0,0);
    while(!q.empty()) {
        auto now = q.front();q.pop();
        int last = now.first;
        int x = now.second;
        
        ans.at(x).at(0) = last;
        for(int i = 1;i<g;i++) {
            ans.at(x).at(i) = ans.at(ans.at(x).at(i - 1)).at(i - 1);
        }

        for(int &i : f.at(x)) if(i != last) q.emplace(x,i);
    }
    return ans;
}
vector<vector<int>> mmax(vector<vector<int>>&f,vector<int>color,int n) {
    int g = __lg(n) + 1;
    vector<vector<int>>ans(n,vector<int>(g));
    queue<pair<int,int>>q;
    q.emplace(0,0);
    while(!q.empty()) {
        auto now = q.front();q.pop();
        int last = now.first;
        int x = now.second;
        
        ans.at(x).at(0) = max(color.at(x),color.at(last));
        for(int i = 1;i<g;i++) {
            ans.at(x).at(i) = max(ans.at(last).at(i - 1),ans.at(ans.at(x).at(i - 1)).at(i - 1));
        }

        for(int &i : f.at(x)) if(i != last) q.emplace(x,i);
    }
    return ans;
}
vector<int> level(vector<vector<int>>&f,int n) {
    vector<int>ans(n);
    queue<pair<int,int>>q;
    q.emplace(0,0);
    while(!q.empty()) {
        auto now = q.front();q.pop();
        int last = now.first;
        int x = now.second;

        ans.at(x) = ans.at(last) + 1;

        for(int &i : f.at(x)) if(i != last) q.emplace(x,i);
    }
    return ans;
}
int check(vector<vector<int>>&f,vector<vector<int>>&mmax,vector<int>&deep,vector<int>&color,int a,int b,int n) {
    if(deep.at(a) > deep.at(b)) swap(a,b);
    int g = __lg(n) + 1;

    int ans = color.at(a);
    for(int i = g - 1;i>=0;i--) {
        if(deep.at(f.at(b).at(i)) >= deep.at(a)) {
            ans = max(ans,mmax.at(b).at(i));
            b = f.at(b).at(i);
        }
    }

    if(a == b) return ans;
    for(int i = g - 1;i>=0;i--) {
        if(f.at(a).at(i) != f.at(b).at(i)) {
            ans = max(ans,mmax.at(a).at(i));
            ans = max(ans,mmax.at(b).at(i));
            a = f.at(a).at(i);
            b = f.at(b).at(i);
        }
    }
    return max(ans,mmax.at(a).at(0));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>a>>b;
    vector<int>color(a);
    for(int &i : color) cin>>i;

    vector<vector<int>>f(a);
    for(int i = 1;i<a;i++) {
        int a,b;cin>>a>>b;
        a--;b--;
        f.at(a).push_back(b);
        f.at(b).push_back(a);
    }
    auto v = init(f,a);
    auto deep = level(f,a);
    auto mark = mmax(f,color,a);

    while(b--) {
        int a,b;cin>>a>>b;
        a--;b--;
        cout<<check(v,mark,deep,color,a,b,::a)<<"\n";
    }
}
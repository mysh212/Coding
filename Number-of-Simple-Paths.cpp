// Author : ysh
// 11/18/2022 Fri  9:21:31.15
// https://codeforces.com/contest/1454/problem/E
// TLE
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int a;cin>>a;
        vector<vector<int>>f(a);
        for(int i = 0;i<a;i++) {
            int a,b;cin>>a>>b;
            a--;b--;
            f.at(a).push_back(b);
            f.at(b).push_back(a);
        }
        vector<bool>mark(a);
        function<int(int)> check = [&] (int x) {
            if(mark.at(x)) return 0;
            mark.at(x) = 1;
            int ans = 1;
            for(int &i : f.at(x)) ans += check(i);
            mark.at(x) = 0;
            return ans;
        };
        int ans = 0;
        for(int i = 0;i<a;i++) {
            ans = ans + check(i) - 1;
        }
        cout<<(ans >> 1)<<"\n";
    }
    return 0;
}
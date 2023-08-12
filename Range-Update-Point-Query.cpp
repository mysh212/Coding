// Author : ysh
// 2023/08/09 Wed 13:45:05
// https://codeforces.com/contest/1791/problem/F
#include<bits/stdc++.h>
using namespace std;
#include<seg_tree>
int check(int x) {
    int ans = 0;
    while(x != 0) {
        ans = ans + (x % 10);
        x = x / 10;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int a,b;cin>>a>>b;
        vector<vector<int>>f(4,vector<int>(a));
        for(int &i : f.at(0)) {
            cin>>i;
        }

        for(int i = 0;i<a;i++) {
            for(int j = 1;j<=3;j++) {
                f.at(j).at(i) = check(f.at(j - 1).at(i));
            }
        }

        seg_tree<int>t(a);
        while(b--) {
            int n;cin>>n;
            if(n == 1) {
                int a,b;cin>>a>>b;
                a--;b--;
                t.add(a,b,1);
            }
            if(n == 2) {
                int a;cin>>a;
                a--;
                int tmp = t.sum(a,a);
                if(tmp > 2) tmp = 3;

                cout<<f.at(tmp).at(a)<<" ";
            }
        }
    }
    return 0;
}
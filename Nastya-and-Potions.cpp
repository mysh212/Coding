// Author : ysh
// 2023/10/14 Sat 22:52:16
// https://codeforces.com/problemset/problem/1851/E
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n,k;cin>>n>>k;
        vector<int>v(n),in(n);
        vector<vector<int>>f(n),re(n);

        for(int &i : v) {
            cin>>i;
        }
        for(int i = 0;i<k;i++) {
            int tmp;cin>>tmp;
            tmp--;
            v.at(tmp) = 0;
        }

        for(int i = 0;i<n;i++) {
            int tmp;cin>>tmp;
            while(tmp--) {
                int n;cin>>n;
                n--;
                f.at(n).push_back(i);
                re.at(i).push_back(n);
                in.at(i)++;
            }
        }

        vector<int>todo;
        queue<int>q;
        for(int i = 0;i<n;i++) {
            if(in.at(i) == 0) q.push(i);
        }

        while(!q.empty()) {
            int now = q.front();q.pop();
            todo.push_back(now);
            for(int &i : f.at(now)) {
                if(--in.at(i) == 0) q.push(i);
            }
        }

        for(int i : todo) {
            if(re.at(i).empty()) continue;
            long long ans = 0;
            for(int &j : re.at(i)) {
                ans = ans + v.at(j);
            }
            v.at(i) = (int) min(ans,1LL * v.at(i));
        }

        for(int &i : v) {
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
// Author : ysh
// 01/26/2023 Thu 17:53:20.68
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        vector<vector<int>>f(n);
        vector<int>g(n);
        vector<int>in(n);
        for(int i = 0;i<n;i++) {
            cin>>g.at(i);
            int tmp;cin>>tmp;
            while(tmp--) {
                int a;cin>>a;
                a--;
                // cerr<<i + 1<<" "<<a + 1<<"\n";
                in.at(a)++;
                f.at(i).push_back(a);
            }
        }
        vector<int>v;
        queue<int>q;
        for(int i = 0;i<n;i++) {
            if(in.at(i) == 0) q.push(i);
        }
        while(!q.empty()) {
            int now = q.front();q.pop();
            v.push_back(now);
            for(int &i : f.at(now)) {
                if(--in.at(i) == 0) q.push(i);
            }
        }
        vector<int>dt = g;
        for(int i = 0;i<n;i++) {
            int &now = v.at(i);
            for(int &j : f.at(now)) {
                dt.at(j) = max(dt.at(j),dt.at(now) + g.at(j));
            }
        }
        // for(int i : dt) cerr<<i<<" ";
        cout<<*max_element(dt.begin(),dt.end())<<"\n";
    }
    return 0;
}
// Author : ysh
// 2023/09/13 Wed 13:04:15
// https://codeforces.com/problemset/problem/1624/C
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        vector<int>f(n);
        priority_queue<int>q;

        for(int &i : f) {
            cin>>i;
            while(i > n) i = i >> 1;
            q.push(i);
        }

        int now = n;
        while(!q.empty()) {
            auto nnow = q.top();q.pop();
            if(nnow < now) goto no;
            if(nnow > now) q.push(nnow >> 1);
            if(nnow == now) now--;
        }

        yes:
        cout<<"yes\n";
        continue;

        no:
        cout<<"no\n";
    }
    return 0;
}
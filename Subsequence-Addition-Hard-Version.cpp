// Author : ysh
// 2023/12/28 Thu 19:47:12
// https://codeforces.com/contest/1807/problem/G2
#include<bits/stdc++.h>
using namespace std;
// #include<fast>
constexpr int R = 200000 + 1;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        deque<int>f(n);
        for(int &i : f) cin>>i;
        sort(f.begin(),f.end());
        
        long long last = 1;
        if(f.front() != 1) goto no;
        else f.pop_front();
        for(int &i : f) {
            if(i > last) goto no;
            last = last + i;
        }

        yes:
        cout<<"YES\n";
        continue;

        no:
        cout<<"NO\n";
    }
    return 0;
}
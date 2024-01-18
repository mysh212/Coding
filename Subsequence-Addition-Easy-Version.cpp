// Author : ysh
// 2023/12/28 Thu 19:32:45
// https://codeforces.com/problemset/problem/1807/G1
#include<bits/stdc++.h>
using namespace std;
constexpr int R = 5000 + 1;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        deque<int>f(n);
        for(int &i : f) cin>>i;
        sort(f.begin(),f.end());

        bitset<R>s;
        s.reset();
        s.set(0);
        s.set(1);
        if(f.front() != 1) goto no;
        else f.pop_front();
        for(int &i : f) {
            if(!s.test(i)) goto no;
            s = s | (s << i);
        }
        yes:
        cout<<"YES\n";
        continue;

        no:
        cout<<"NO\n";
    }
    return 0;
}
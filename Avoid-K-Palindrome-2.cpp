// Author : ysh
// 2024/08/05 Mon 11:13:48
// https://atcoder.jp/contests/abc363/tasks/abc363_c
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    string n;cin>>n;

    sort(n.begin(),n.end());
    int ans = 0;
    do {
        for(int i = 0;i <= a - b;i++) {
            string tmp = n.substr(i,b);
            string t = tmp;
            reverse(t.begin(),t.end());
            if(tmp == t) goto no;
        }

        yes:
            ans++;
        no:
            continue;
    } while(next_permutation(n.begin(),n.end()));

    cout<<ans;
    return 0;
}
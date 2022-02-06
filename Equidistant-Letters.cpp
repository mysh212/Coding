// Author : ysh
// 02/06/2022 Sun  8:17:27.78
// https://codeforces.com/contest/1626/problem/A
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    bitset<27>a;
    bitset<27>b;
    int n;cin>>n;
    while(n--) {
        a.reset();
        b.reset();
        string r;cin>>r;
        for(char t : r) {
            int now = (int) (t - 'a');
            if(a.test(now) == 1) {
                a[now] = 0;
                b[now] = 1;
            } else {
                a[now] = 1;
            }
        }
        bool ok = 0;
        for(int i = 0;i<26;i++) {
            if(b[i]) cout<<(char) (i + 'a')<<(char) (i + 'a');
        }
        for(int i = 0;i<26;i++) {
            if(a[i]) cout<<(char) (i + 'a');
        }
        cout<<"\n";
    }
    return 0;
}
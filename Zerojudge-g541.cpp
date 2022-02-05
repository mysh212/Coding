#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a,b,m;cin>>a>>b>>m;
    if(a>b) swap(a,b);
    while(m--) {
        int n;cin>>n;
        int limit = n / a;
        int tmp = n;
        int flag = 0;
        while(tmp >= 0) {
            if(((tmp)) % b == 0) {
                flag = 1;
            }
            tmp-=a;
        }
        cout<<((flag) ? "YES\n" : "NO\n");
    }
    return 0;
}
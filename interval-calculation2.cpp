// http://choj.me/problem/00140
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int r;cin>>r;



    while(r--){
        long long n,m;
        long long ans = 0;
        cin>>n>>m;
        vector<long long> a(n);
        vector<long long> b(n+1);
        unordered_multiset<long long> f;
        for(int  i = 0;i<n;i++) {
            cin>>a[i];
            b[i+1] = b[i] + a[i];
            //printf("f[%d]++",b[i]);
            //pci();
        }
        long long tmp;
        for(int i = 1;i<=n;i++) {
            tmp = b[i] - m;
            if(tmp == 0) ans++;
            auto now = f.count(tmp);
            ans += now;
            f.insert(b[i]);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
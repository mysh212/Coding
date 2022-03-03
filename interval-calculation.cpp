// http://choj.me/problem/00140
#include<bits/stdc++.h>
using namespace std;
void pc(long long*,int);
int main() {
    //freopen("4.in","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int r;cin>>r;



    while(r--){
    long long n,m;
    long long ans = 0;
    cin>>n>>m;
    vector<long long> a(n);
    vector<long long> b(n+1);
    auto pci = [&] () {
        for(int i = 0;i<n;i++) {
        cout<<b[i]<<" ";
        }
        cout<<"\n";
        return;
    };
    // cin>>a[0];
    // b[0] = a[0];
    //pci();
    unordered_map<long long,int> f;
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
        auto now = f.find(tmp);
        if(now != f.end()) {
            ans += now->second;
        }
        f[b[i]]++;
        /*
        for(int j = i + 1;j<n;j++) {
            if(b[j] == tmp) ans++;
        }
        */
    }
    cout<<ans<<"\n";
    }
    //cout<<"["<<clock()<<"]";
    return 0;
}
void pc(long long* c,int n) {
    for(int i = 0;i<n;i++) {
        cout<<c[i]<<" ";
    }
    cout<<"\n";
    return;
}
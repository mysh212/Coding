// Author : ysh
// 02/10/2022 Thu 14:54:20.98
// http://choj.me/problem/00007
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    int a[n] = {};
    map<int,int>f;
    {
    int b[n+1] = {};
    for(int i = 0;i<n;i++) {
        cin>>a[i];
        b[i] = a[i];
    }
    sort(b,b+n);
    for(int i = 0;i<n;i++) {
        if(f.find(b[i]) == f.end()) {
            f[b[i]] = i + 1;
        }
    }
    }
    int b[n+1] = {};
    for(int i = 0;i<n;i++) {
        int tttmp = f[a[i]];
        int tmp = b[tttmp];
        int ttmp = b[tttmp - 1];
        if(ttmp + a[i] > tmp) {
            b[f[a[i]]] = ttmp + a[i];
        } else {
            continue;
        }
        for(int j = tttmp + 1;j<=n;j++) {
            if(b[j - 1]>b[j]) {
                b[j] = b[j - 1];
            } else {
                break;
            }
            //b[j] = max(b[j - 1],b[j]);
        }

        //for(int k : b) cout<<k<<" ";
        //cout<<"\n";
    }
    cout<<b[n];
    return 0;
}
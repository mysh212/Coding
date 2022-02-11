// Author : ysh
// 02/11/2022 Fri 20:21:04.86
// http://choj.me/problem/00008
// WA
#include<bits/stdc++.h>
using namespace std;
bool is;
int k;
inline int cp(int a,int b) {
    if(a<=k) {
        if(b <= k) {
            if(a>b) {
                is = 0;
                return a;
            } else {
                is = 1;
                return b;
            }
        } else {
            return a;
        }
    } else {
        return b;
        is = 1;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    cin>>k;
    int a[n] = {};
    int c[n][n] = {};
    for(int &i : a) {
        cin>>i;
    }
    for(int i = 0;i<n;i++) {
        if(a[i] <= k) c[i][i] = a[i];
        int mmax = 0;
        for(int r = 0;r<i;r++) {
            for(int j = r;j<i;j++) {
                if(c[j][r] + a[i] <= k) {
                    mmax = max(mmax,c[j][r] + a[i]);
                } else {
                    mmax = max(mmax,c[j][r]);
                }
            }
            c[i][r] = mmax;
        }
    }
    int mmax = 0;
    for(int i = 0;i<n;i++) {
        mmax = max(mmax,c[n-1][i]);
    }
    /*
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n;j++) {
            cout<<c[i][j]<<" ";
        }
        cout<<"\n";
    }
    */
    cout<<mmax;
    return 0;
}
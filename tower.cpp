// Author : ysh
// 05/22/2022 Sun 11:25:42.78
// https://apcsclass.csie.ntnu.edu.tw/ShowProblem?problemid=a155
// WA
#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>aa,bb;
int a,b;
int check();
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = 1;
    while(cin>>a>>b) {
        if(a == 0 && b == 0) break;
        cout<<"Twin Towers #"<<n++<<"\n";
        aa.resize(a);bb.resize(b);
        for(int i = 0;i<a;i++) {
            cin>>aa[i];
        }
        for(int i = 0;i<b;i++) {
            cin>>bb[i];
        }
        cout<<"Number of Tiles : ";
        cout<<check();
        cout<<"\n\n";
    }
    return 0;
}
int check() {
    //cout<<"\n";
    int c[b + 1][a + 1] = {};
    for(int i = 0;i<b;i++) {
        for(int j = 0;j<a;j++) {
            if(aa[i] == bb[j]) {
                c[i + 1][j + 1] = c[i][j] + 1;
            } else {
                c[i + 1][j + 1] = max(c[i][j + 1],c[i + 1][j]);
            }
            //cout<<c[i + 1][j + 1]<<" ";
        }
        //cout<<"\n";
    }
    return c[b][a];
}
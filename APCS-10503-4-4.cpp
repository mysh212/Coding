// Author : ysh
// 01/07/2023 Sat 21:56:45.51
#include<bits/stdc++.h>
using namespace std;
int mmax,d;
vector<vector<int>>f;
void check(int c,int a,int b) {
    if(b > mmax) {
        mmax = b;
        d = a;
    }
    for(int &i : f.at(a)) {
        if(i != c) check(a,i,b + 1);
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while(cin>>n) {
        d = mmax = 0;
        f.clear();
        f.resize(n);
        for(int i = 1;i<n;i++) {
            int a,b;cin>>a>>b;
            f.at(a).push_back(b);
            f.at(b).push_back(a);
        }
        check(-1,0,0);
        mmax = 0;
        check(-1,d,0);
        cout<<mmax<<"\n";
    }
    return 0;
}
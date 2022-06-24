// Author : ysh
// 06/15/2022 Wed 19:51:45.00
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    bitset<1001>b;
    b.reset();
    int mmax = INT_MIN,mmin = INT_MAX;
    for(int i = 0;i<n;i++) {
        int tmp;cin>>tmp;
        mmax = max(mmax,tmp);
        mmin = min(mmin,tmp);
        b.set(tmp);
    }
    cout<<mmin<<" "<<mmax<<" ";
    int last = b._Find_first() - 1;
    for(int i = b._Find_first();i<1001;i = b._Find_next(i)) {
        if(++last != i) {
            cout<<"no";
            return 0;
        }
    }
    cout<<"yes";
    return 0;
}
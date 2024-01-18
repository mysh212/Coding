// Author : ysh
// 2024/01/12 Fri 16:48:01
#include<bits/stdc++.h>
using namespace std;
#define last(i,j) (f.at(j) - (i == 0 ? 0 : f.at(i - 1)))
vector<vector<int>>mark;
int check(vector<int>&f,int l,int r) {
    if(l == r) return 0;
    if(mark.at(l).at(r) != -1) return mark.at(l).at(r);
    int mmin = INT_MAX;
    for(int i = l;i<r;i++) {
        mmin = min(check(f,l,i) + abs(last(l,i) - last(i + 1,r)) + check(f,i + 1,r),mmin);
    }
    // cout<<l<<" "<<r<<" "<<mmin<<"\n";
    return mark.at(l).at(r) = mmin;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    mark.resize(n,vector<int>(n,-1));
    vector<int>f(n);
    int last = 0;
    for(int &i : f) {
        cin>>i;
        i = last += i;
    }
    
    cout<<check(f,0,n - 1);
    return 0;
}
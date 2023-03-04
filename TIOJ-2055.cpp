// Author : ysh
// 03/04/2023 Sat 20:07:14.68
// https://tioj.ck.tp.edu.tw/problems/2055
#include<bits/stdc++.h>
using namespace std;
vector<int>f;
int n;
#define left(i) ((i << 1) + 1)
#define right(i) ((i << 1) + 2)
void mt(vector<int>&v,int t = 0,int nl = -1,int nr = -1) {
    if(nl == -1 && nr == -1) nl = 0,nr = n - 1;
    if(nl == nr) return f.at(t) = v.at(nl),void();
    int mid = (nl + nr) >> 1;
    mt(v,left(t),nl,mid);
    mt(v,right(t),mid + 1,nr);
    f.at(t) = min(f.at(left(t)),f.at(right(t)));
    return;
}
#define eo(i) i //(cout<<#i<<" "<<i<<"\n",i)
int get(int l,int r,int t = 0,int nl = -1,int nr = -1) {
    if(nl == -1 && nr == -1) nl = 0,nr = n - 1;
    if(l > r) swap(l,r);
    if(nr < l || nl > r) return INT_MAX;
    if(nl >= l && nr <= r) return f.at(t);
    int mid = (nl + nr) >> 1;
    return min(eo(get(l,r,left(t),nl,mid)),eo(get(l,r,right(t),mid + 1,nr)));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    vector<int>f(n);
    for(int &i : f) {
        cin>>i;
    }
    ::f.resize(n << 2);
    mt(f);
    // for(int i : ::f) cout<<i<<" ";
    // cout<<"\n";
    int a,b;
    while(cin>>a>>b) {
        cout<<get(a - 1,b - 1) + 1<<"\n";
    }
    return 0;
}
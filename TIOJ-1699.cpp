// Author : ysh
// 02/12/2023 Sun 13:00:08.49
// https://tioj.ck.tp.edu.tw/problems/1699
#include<bits/stdc++.h>
using namespace std;
vector<int>f;
int n;
void mt(int n) {
    f.resize(n << 2);
    ::n = n;
    return;
}
void add(int x,int v,int t = 0,int nl = -1,int nr = -1) {
    if(nl == -1 && nr == -1) nl = 0,nr = n - 1;
    if(nl == nr) return f.at(t) += v,void();
    int mid = (nl + nr) >> 1;
    if(x <= mid) add(x,v,(t << 1) + 1,nl,mid);
    else add(x,v,(t << 1) + 2,mid + 1,nr);
    f.at(t) = max(f.at((t << 1) + 1),f.at((t << 1) + 2));
    return;
}
#define get f.at(0)
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>v(a);
    for(int &i : v) cin>>i;

    int t = 0;
    vector<array<int,4>>q(b);
    for(auto &i : q) cin>>i[0]>>i[1]>>i[2],i[0]--,i[1]--,i[2] = ceil((i[1] - i[0] + 1) * 1.0 / i[2]),i[3] = t++;
    // for(auto &i : q) cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<"\n";

    sort(q.begin(),q.end());
    mt(a + 1);
    int l = 0,r = 0;
    add(f.at(0),1);
    vector<bool>ans(b);
    for(auto &i : q) {
        int x = i[0];
        int y = i[1];
        int z = i[2];
        while(l < x) add(f.at(l++),-1);
        while(l > x) add(f.at(--l),1);
        while(r < y) add(f.at(++r),1);
        while(r > y) add(f.at(r--),-1);
        ans.at(i[3]) = (get >= z);
    }
    for(bool i : ans) cout<<(i ? "Yes" : "No")<<"\n";
    return 0;
}
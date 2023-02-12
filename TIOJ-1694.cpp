// Author : ysh
// 02/12/2023 Sun  8:10:29.97
// https://tioj.ck.tp.edu.tw/problems/1694
#include<bits/stdc++.h>
using namespace std;
#include<fast>
#include<tree>
const int R = 151;
struct box{
    int first = 0,second = 0,i = 0;
    box():
        first(0), second(0), i(0) {};
    inline bool operator<(const box &a) const {
        if(first / R == a.first / R) return first < a.first;
        return first / R < a.first / R;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    int T = sqrt(a);
    vector<int>f(a);
    for(int &i : f) cin>>i;
    tree<int>t(a + 1);

    vector<box>v(b);
    int e = 0;
    for(auto &i : v) {
        cin>>i.first>>i.second;
        i.i = e++;
        i.first--;i.second--;
    }
    sort(v.begin(),v.end(),[&] (box &a,box &b) {
        return a.first / T < b.first / T;
    });

    int l,r;l = r = 0;
    vector<int>ans(b);
    t.add(f.at(0),1);
    int now = 0;
    for(auto &i : v) {
        int x = i.first;
        int y = i.second;
        while(l < x) t.add(f.at(l++),-1),now = now - t.sum(0,f.at(l - 1) - 1);
        while(l > x) t.add(f.at(--l),1),now = now + t.sum(0,f.at(l) - 1);
        while(r < y) t.add(f.at(++r),1),now = now + t.sum(f.at(r) + 1,a);
        while(r > y) t.add(f.at(r--),-1),now = now - t.sum(f.at(r + 1) + 1,a);
        ans.at(i.i) = now;
    }
    for(int &i : ans) cout<<i<<"\n";
    return 0;
}
// Author : ysh
// 01/25/2023 Wed 16:35:08.08
// https://codeforces.com/contest/1792/problem/C
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        vector<int>f(n),l(n);
        int t = 0;
        for(int &i : f) {
            cin>>i;
            i--;
            l.at(i) = t++;
        }
        function<bool(int)> check = [&] (int x) {
            return (is_sorted(l.begin() + x,l.end() - x));
        };
        function<int(int,int)> ck = [&] (int l,int r) {
            if(l == r) return l;
            int mid = (l + r) >> 1;
            if(check(mid)) return ck(l,mid);
            else return ck(mid + 1,r);
        };
        cout<<ck(0,n >> 1)<<"\n";
    }
    return 0;
}
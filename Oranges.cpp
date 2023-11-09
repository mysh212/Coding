// Author : ysh
// 2023/08/24 Thu 21:43:40
// https://codeforces.com/group/bzV2fc45zy/contest/463655/problem/H
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n);
    for(int &i : f) {
        cin>>i;
    }

    int ans = 0;
    function<int(int,int)> check = [&] (int l,int r) {
        if(l == r) return ans = max(ans,f.at(l)),l;

        int mid = (l + r) >> 1;
        int ll = check(l,mid);
        int rr = check(mid + 1,r);
        if(f.at(ll) < f.at(rr)) swap(ll,rr);
        int nl,nr;nl = nr = (f.at(mid) > f.at(mid + 1) ? mid : mid + 1);
        int mmin = max(f.at(mid),f.at(mid + 1));

        while(nl > l && f.at(nl) >= mmin) nl--;
        while(nr < r && f.at(nr) >= mmin) nr++;
        ans = max(ans,mmin * (nr - nl + 1));

        while(nl != l || nr != r) {
            cerr<<nl<<" "<<nr<<" "<<mmin<<"\n";
            mmin = min(max((nl == l ? INT_MIN : f.at(nl - 1)),(nr == r ? INT_MIN : f.at(nr + 1))),mmin);
            while(nl > l && f.at(nl - 1) >= mmin) nl--;
            while(nr < r && f.at(nr + 1) >= mmin) nr++;
            ans = max(ans,mmin * (nr - nl + 1));
        }

        return ll;
    };

    check(0,n - 1);
    cout<<ans;
    return 0;
}
// Author : ysh
// 05/02/2023 Tue 23:48:53.28
// https://judge.tcirc.tw/ShowProblem?problemid=b036
#include<bits/stdc++.h>
using namespace std;
#include<fast>
vector<int>f;
long long check(int l,int r) {
    if(l == r) return 0;
    int mid = (l + r) >> 1;
    long long ll = check(l,mid);
    long long rr = check(mid + 1,r);

    long long ans = 0;
    for(int i = mid + 1;i<=r;i++) {
        auto found = upper_bound(f.begin() + l,f.begin() + mid + 1,f.at(i));
        ans = ans + f.begin() + mid + 1 - found;
    }

    vector<int>tmp;
    int nl = l,nr = mid + 1;
    for(int i = l;i<=r;i++) {
        if(nl == mid + 1) tmp.push_back(f.at(nr)),nr++;
        else if(nr == r + 1) tmp.push_back(f.at(nl)),nl++;
        else if(f.at(nl) <= f.at(nr)) tmp.push_back(f.at(nl)),nl++;
        else if(f.at(nl) > f.at(nr)) tmp.push_back(f.at(nr)),nr++;
    }
    for(int i = l;i<=r;i++) {
        // cerr<<tmp.at(i - l)<<" ";
        f.at(i) = tmp.at(i - l);
    }
    // cerr<<"\n";
    return (ll + rr) + ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    f = vector<int>(n);
    for(int &i : f) {
        cin>>i;
    }
    cout<<check(0,n - 1);
    return 0;
}
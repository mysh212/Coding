#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans = 0;
vector<int>f;
void check(int l,int r) {
    if(l == r) return;
    int mid = (l + r) >> 1;
    if(l + 1 == r) {
        if(f.at(l) > f.at(r)) {
            swap(f.at(l),f.at(r));
            ans++;
        }
        return;
    }
    check(l,mid);
    check(mid + 1,r);
    for(int i = mid + 1;i <= r;i++) {
        auto found = upper_bound(f.begin() + l,f.begin() + mid + 1,f.at(i));
        ans += (mid + 1) - ((found - f.begin()));
    }
    sort(f.begin() + l,f.begin() + r + 1);
    return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    f.resize(n);
    for(int &i : f) {
        cin>>i;
    }
    check(0,n - 1);
    cout<<ans;
    return 0;
}

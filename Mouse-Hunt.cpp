// Author : ysh
// 12/07/2022 Wed 11:45:56.90
// https://codeforces.com/contest/1027/problem/D
#include<bits/stdc++.h>
using namespace std;
vector<bool>mark,put,mk;
vector<int>cost;
vector<vector<int>>f;
vector<int>re;
int ans = 0;
int ck(int x) {
    int mmin = cost.at(x);
    int d = x;
    if(put.at(x)) return ans;
    int r = x;
    x = re.at(x);
    while(x != r) {
        // cerr<<x<<" "<<r<<"\n";
        if(put.at(x)) return ans;
        if(cost.at(x) < mmin) {
            d = x;
            mmin = cost.at(x);
        }
        x = re.at(x);
    }
    put.at(d) = 1;
    return ans += mmin;
}
void check(int x) {
    if(mk.at(x)) return;
    if(mark.at(x)) {
        ck(x);
        return;
    }
    mark.at(x) = 1;
    for(int &i : f.at(x)) {
        re.at(i) = x;
        check(i);
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    mk.resize(n);
    put.resize(n);
    mark.resize(n);
    cost.resize(n);
    f.resize(n);
    re.resize(n);
    for(int &i : cost) cin>>i;
    for(int i = 0;i<n;i++) {
        int tmp;cin>>tmp;
        f.at(i).push_back(tmp - 1);
    }
    for(int i = 0;i<n;i++) if(!mark.at(i)) {
        check(i);
        mk = mark;
    }
    cout<<ans;
    return 0;
}
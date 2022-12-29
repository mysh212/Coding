// Author : ysh
// 12/29/2022 Thu 20:15:34.16
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n);
    for(int &i : f) {
        cin>>i;
    }
    vector<int>re(n,-1);
    reverse(f.begin(),f.end());
    bool r = 0;
    int p = 0;
    function<int(int,int,int,int)> check = [&] (int last,int x,int mmax,int mmin) {
        debug(x,mmax,mmin);
        if(p + 1 == n) return 0;
        if(f.at(p + 1) < mmin || f.at(p + 1) > mmax) return 0;
        debug(x);
        if(f.at(p + 1) > f.at(x)) {
            p++;
            re.at(p) = x;
            check(x,p,mmax,f.at(p - 1));
        }
        if(p + 1 == n) return 0;
        if(f.at(p + 1) < mmin || f.at(p + 1) > mmax) return 0;
        if(f.at(p + 1) < f.at(x)) {
            p++;
            re.at(p) = x;
            check(x,p,f.at(p - 1),mmin);
        }
        return 0;
    };
    check(0,0,INT_MAX,INT_MIN);
    vector<pair<int,int>>ans;
    for(int i = 0;i<n;i++) {
        if(re.at(i) == -1) ans.push_back({f.at(i),-1});
        else ans.push_back({f.at(i),f.at(re.at(i))});
    }
    sort(ans.begin(),ans.end());
    for(auto &i : ans) {
        cout<<i.first<<" "<<i.second<<"\n";
    }
    return 0;
}
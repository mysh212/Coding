// Author : ysh
// 2024/01/18 Thu 17:02:49
#include<bits/stdc++.h>
using namespace std;
#include<slow>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<pair<int,int>>f(n);
    cin>>f;

    sort(all(f));
    int l = -1,r = -1;
    int ans = 0;

    repo(&i,f) {
        if(i.first > r) {
            ans = ans + (r - l);
            l = i.first;
            r = i.second;
        }
        r = max(r,i.second);
    }
    ans = ans + (r - l);
    cout<<ans;
    return 0;
}
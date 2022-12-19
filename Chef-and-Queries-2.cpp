// Author : ysh
// 12/15/2022 Thu 20:00:10.18
// https://www.codechef.com/problems/CHEFQUE
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
gp_hash_table<long long,null_type>f;
long long ans = 0;
void check(long long r) {
    if(!(r & 1)) {
        r = r >> 1;
        if(!(f.find(r) != f.end())) return;
        f.erase(r);
        ans = ans - r;
        return;
    }
    r = r >> 1;
    if((f.find(r) != f.end())) return;
    f.insert(r);
    ans = ans + r;
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    long long a,b,c;cin>>a>>b>>c;
    while(n--) {
        check(a);
        a = ((long long) (a * b + c)) & ((1LL << 32) - 1);
    }
    cout<<ans;
    return 0;
}
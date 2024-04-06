// Author : ysh
// 2024/03/30 Sat 12:07:20
#include<bits/stdc++.h>
using namespace std;
const int R = 1e5;
bitset<R>s;
vector<int>prime;
void init() {
    for(int i = 2;i<R;i++) {
        if(s.test(i)) continue;
        prime.push_back(i);
        for(long long j = 1LL * i * i;j<R;j = j + i) {
            s.set(j);
        }
    }
    return;
}
vector<int> check(int x) {
    vector<int>ans;
    for(int &i : prime) {
        if(i * i > x) break;
        while(x % i == 0) ans.push_back(i),x = x / i;
    }
    if(x != 1) ans.push_back(x);
    sort(ans.begin(),ans.end());
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();
    int n;cin>>n;
    auto f = check(n);
    if(f.size() != 2) return cout<<"0 0",0;
    for(int &i : f) cout<<i<<" ";
    return 0;
}
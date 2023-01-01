// Author : ysh
// 12/31/2022 Sat 22:17:08.52
#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>f;
const int R = 32768;
bitset<R + 1>s;
void init() {
    s.reset(2);
    for(int i = 2;i<R;i++) {
        if(s.test(i)) continue;
        f.push_back({i * i,i});
        s.reset(i);
        for(int j = i * i;j < R;j = j + i) {
            s.set(j);
        }
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();
    int n;cin>>n;
    int m = f.size();
    int ans = 1;
    for(int j = 0;j<m;j++) {
        auto &i = f.at(j);
        if(i.first > n) break;
        if(n % (i.first) == 0) {
            n = n / i.first;
            ans = ans * i.second;
            j--;
        }
    }
    if(n == 1) {
        cout<<ans;
        return 0;
    }
    if(ans == 1) {
        cout<<"sqrt("<<n<<")";
        return 0;
    }
    cout<<ans<<" sqrt("<<n<<")";
    return 0;
}
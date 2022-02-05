#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;cin>>n;
    int ans = 0;
    int c[n] = {};
    vector<int> v;
    for(int i = 0;i<n;i++) {
        cin>>c[i];
        if(c[i] == 0) v.push_back(i);
    }
    while(!(v.empty())) {
        int i = v.back();
        v.pop_back();
        if(c[i] == 0&&i == 0) {
            ans += c[1];
        } else if(c[i] == 0&&i == (n - 1)) {
            ans += c[i - 1];
        } else if(c[i] == 0) {
            ans += min(c[i - 1],c[i + 1]);
        }
    }
    cout<<ans;
    return 0;
}
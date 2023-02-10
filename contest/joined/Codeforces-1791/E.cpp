// Author : ysh
// 02/03/2023 Fri 23:12:58.83
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        vector<int>f(n);
        bool c = 0;
        bool d = 0;
        long long sig = 0;
        for(int &i : f) cin>>i,c = (i < 0 ? !c : c),d = (i == 0 ? 1 : d),sig = sig + abs(i),i = abs(i);
        sort(f.begin(),f.end());
        if(c && !d) sig = sig - (f.at(0) << 1);
        cout<<sig<<"\n";
    }
    return 0;
}
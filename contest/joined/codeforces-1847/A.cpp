// Author : ysh
// 2023/07/06 Thu 22:33:50
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int a,b;cin>>a>>b;
        b--;
        vector<int>f(a),v;
        for(int &i : f) cin>>i;

        for(int i = 1;i<a;i++) {
            v.push_back(abs(f.at(i) - f.at(i - 1)));
        }
        sort(v.rbegin(),v.rend());

        int sig = 0;
        for(int i = 0;i<b;i++) {
            sig += v.at(i);
        }
        cout<<accumulate(v.begin(),v.end(),0) - sig<<"\n";
    }
    return 0;
}
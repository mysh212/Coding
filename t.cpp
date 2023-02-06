// Author : ysh
// 02/06/2023 Mon 11:32:44.42
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n);
    for(int &i : f) cin>>i;
    vector<int>g(f);
    int m;cin>>m;
    while(m--) {
        int a,b;cin>>a>>b;
        a--;b--;
        swap(f.at(a),f.at(b));
    }
    cerr<<n<<"\n";
    for(int &i : g) cerr<<i<<" ";
    cerr<<"\n";
    for(int &i : f) cerr<<i<<" ";
    cout<<boolalpha<<is_sorted(f.begin(),f.end());
    return 0;
}
// Author : ysh
// 02/10/2023 Fri 10:47:22.17
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;cout<<n<<"\n";
    vector<int>f(n);
    iota(f.begin(),f.end(),1);
    srand(time(NULL));
    random_shuffle(f.begin(),f.end());
    for(int i : f) cout<<i<<" ";
    cout<<"\n";
    for(int i : f) cerr<<i<<" ";
    cerr<<"\n";
    random_shuffle(f.begin(),f.end());
    for(int i : f) cout<<i<<" ";
    for(int i : f) cerr<<i<<" ";
    cerr<<"\n";
    return 0;
}
// Author : ysh
// 02/10/2023 Fri 10:47:22.17
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("0.in","w",stderr);
    int n;cin>>n;cout<<n<<"\n";cerr<<n<<"\n";
    vector<int>f(n);
    srand(time(NULL));
    set<int>s;
    for(int &i : f) {
        i = rand();
        while(s.count(i)) {
            i = rand();
        }
        s.insert(i);
    }
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
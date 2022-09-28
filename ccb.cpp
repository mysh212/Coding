// Author : ysh
// 09/21/2022 Wed 10:39:43.99
using namespace std;
#include<square>
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    t<int> tt(2);
    int n;
    while(cin>>n) {
        vector<vector<int>>l({{0,1},{0,1}});
        vector<vector<int>>r({{0,1},{1,1}});
        if(n == 0) cout<<"0\n";
        else if(n == 1) cout<<1<<"\n";
        else cout<<(((t<int>(r)) ^ (n - 1)) * t<int>(l)).f.at(0).at(1)<<"\n";
    }
    return 0;
}
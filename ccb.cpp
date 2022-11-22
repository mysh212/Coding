// Author : ysh
// 11/22/2022 Tue 23:10:35.62
using namespace std;
#include<seg_tree>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,b;cin>>n>>b;
    vector<long long>f(n);
    for(long long &i : f) {
        cin>>i;
    }
    seg_tree<long long>t(f);
    while(b--) {
        int a,b,c;cin>>a>>b>>c;
        if(a == 1) {
            b--;
            t.add(1,0,n - 1,b,b,c - f.at(b));
            f.at(b) = c;
            continue;
        }
        b--;c--;
        cout<<t.sum(1,0,n - 1,b,c)<<"\n";
    }
    return 0;
}
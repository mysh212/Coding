// Author : ysh
// 12/29/2022 Thu 21:25:07.10
using namespace std;
#define int long long
#include<seg_tree>
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>f(a);
    for(int &i : f) {
        cin>>i;
    }
    seg_tree<int>t(f);
    int aa,bb;aa = bb = 0;
    bool l = 1;
    while(b--) {
        int a,b,c;cin>>c>>a>>b;
        if(c == 1) {
            if(l) aa = aa + t.sum(a - 1,b - 1);
            else bb = bb + t.sum(a - 1,b - 1);
        }
        if(c == 3) {
            t.add(a - 1,a - 1,b - f.at(a - 1));
            f.at(a - 1) = b;
        }
        l = !l;
    }
    cout<<aa<<"\n"<<bb;
    return 0;
}
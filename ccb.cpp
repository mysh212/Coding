// Author : ysh
// 11/12/2022 Sat  9:14:37.13
using namespace std;
#define cp(a,b) max(a,b)
#include<seg_tree>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n);
    for(int &i : f) {
        cin>>i;
    }
    seg_tree<int>t(f,[] (int a,int b) {
        return max(a,b);
    });
    int m;cin>>m;
    while(m--) {
        int a,b;cin>>a>>b;
        a--;b--;
        if(a > b) swap(a,b);
        cout<<t.sum(a,b)<<"\n";
    }
    return 0;
}
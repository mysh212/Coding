// Author : ysh
// 09/19/2022 Mon 10:35:28.99
using namespace std;
#include<seg_tree>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m;cin>>m;
    while(m--) {
        int n;cin>>n;
        seg_tree<int> d(n,[] (int a,int b) {
            return min(a,b);
        });
        seg_tree<int> u(n,[] (int a,int b) {
            return max(a,b);
        });
        for(int i = 0;i<n;i++) {
            string a;cin>>a;
            for(int j = 0;j<n;j++) {
                if(a[j] == '1') {
                    d.add(j,i);u.add(j,i);
                }
            }
        }
        int ans = 0;
        for(int i = 0;i<n;i++) {
            for(int j = i;j<n;j++) {
                int dd = d.sum(i,j);
                int uu = u.sum(i,j);
                if(uu - dd == j - i) ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define bigger "abundant\n"
#define equal "perfect\n"
#define smaller "deficient\n"
//#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int tmp;cin>>tmp;
        if(tmp == 1) {
        	cout<<smaller;
        	continue;
		}
        int ans = 0;
        //int r = sqrt(tmp);
        for(int i = 1;i * i <= tmp;i++) {
            if(tmp % i == 0) {
                    ans = ans + i;
                    if(i != 1 && i * i != tmp) ans += (tmp / i);
            }
        }
        if(ans > tmp) cout<<bigger;
        if(ans == tmp) cout<<equal;
        if(ans < tmp) cout<<smaller;
    }
    return 0;
}

// Author : ysh
// 01/23/2022 Sun 13:12:02.92
#include<bits/stdc++.h>
using namespace std;
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    srand(time(NULL));
    int n;cin>>n;
    cout<<n<<"\n";
    while(n--) {
        printf("%d %d %d %d\n",rand()%200+1,rand()%200+1,rand()%200+1,rand()%200+1);
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n = 1,ans = 1;
    int j = 1;
    while(cin>>n) {
        for(int i = 0;i<j;i++) {
            ans = ans * ((n-i) % 76543);
            ans = ans % 76543;
        }
        j++;
    }
    cout<<ans;
}
#include<bits/stdc++.h>
using namespace std;
int main() {
    int a,b,n;cin>>a>>b>>n;
    if(a>b) swap(a,b);
    int limit = n / a;
    int tmp = 0;
    while(tmp <= limit) {
        if((n - (a * tmp)) % b == 0) {
            cout<<"YES";
            return 0;
        }
        tmp++;
    }
    cout<<"NO";
    return 0;
}
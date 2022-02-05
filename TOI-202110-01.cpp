#include<bits/stdc++.h>
using namespace std;
int main() {
    int a,b;cin>>a>>b;
    cout<<(b % a == 0 ? b/a : b/a + 1);
    return 0;
    /*
    if(b % a == 0) {
        cout<<b/a;
        return 0;
    } else {
        cout<<b/a + 1;
        return 0;
    }
    */
}
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a,b;
    while(cin>>a>>b) {
        int n = 0;
        while(1) {
            n++;
            if(n*a%b == 1) {
                cout<<n<<"\n";
                break;
            }
            if(n > a) {
                cout<<"No Inverse\n";
                break;
            }
        }
    }
    return 0;
}
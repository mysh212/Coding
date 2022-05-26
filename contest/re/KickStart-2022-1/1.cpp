#include<iostream>
using namespace std;
int main() {
    int n;cin>>n;
    for(int j = 1;j<=n;j++) {
        int a,b;cin>>a>>b;
        int c = 0;
        int tmp;
        for(int i = 0;i<a;i++) {
            cin>>tmp;
            c += tmp;
        }
        cout<<"Case #"<<j<<": "<<c % b<<"\n";
    }
    return 0;
}
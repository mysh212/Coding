#include<bits/stdc++.h>
using namespace std;
int check(int,int,int);
int main() {
    int a;cin>>a;
    int n;cin>>n;
    int p;cin>>p;
    cout<<check(a,n,p) % p;
    return 0;
}
int check(int a,int b,int c) {
    if(b == 0) return 1;
    else return a * (check(a,b - 1,c) % c);
}
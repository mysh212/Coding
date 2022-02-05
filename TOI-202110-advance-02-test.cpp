#include<bits/stdc++.h>
using namespace std;
int check(string);
void run(int*,int);
int main() {
    string a;cin>>a;
    a = a.replace(a.find("A"),1,"1");
    a = a.replace(a.find("A"),1,"1");
    a = a.replace(a.find("A"),1,"1");
    cout<<a;
}
#include<iostream>
#include<string.h>
#include<random>
#include<ctime>
using namespace std;
int main() {
    string a;cin>>a;
    for(int i = 1;i<a.length();i++) {
        cout<<a.substr(0,i)<<"\n";
    }
}
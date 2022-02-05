#include<iostream>
#include<sstream>
using namespace std;
int main() {
    string a;
    stringstream b;
    getline(cin,a);
    b<<a;
    cout<<a<<"\n";
    b>>a;
    cout<<a<<"\n";
}
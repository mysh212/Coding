#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    vector<int>f;
    f.push_back(1);
    f.push_back(2);
    f.insert((vector<int>::iterator) &f[1],0);
    for(int i : f) {
        cout<<i;
    }
    cout<<*(f.end()-1);
    vector<int>g(f.begin(),f.end());
    for(int i : g) {
        cout<<i;
    }
    int a[3] = {1,2,3};
    vector<int>h(10,3);
    for(int i : h) {
        cout<<i;
    }
    vector<int>l(a,a+3);
    reverse(l.begin(),l.end());
    for(int i : l) {
        cout<<i;
    }
}
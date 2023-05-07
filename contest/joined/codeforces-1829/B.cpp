// Author : ysh
// 05/06/2023 Sat 22:39:15.67
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        vector<int>f(n);
        for(int &i : f) {
            cin>>i;
            if(i == 1) i = 0;
            else i = 1;
        }
        for(int i = 0;i<n;i++) {
            if(f.at(i) == 1 && i != 0) f.at(i) = f.at(i - 1) + 1;
        }
        cout<<*max_element(f.begin(),f.end())<<"\n";
    }
    return 0;
}
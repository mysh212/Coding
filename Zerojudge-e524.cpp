// Author : ysh
// 10/20/2022 Thu  9:09:10.80
#include<bits/stdc++.h>
using namespace std;
constexpr int R = 'A' - 'a';
inline char lower(char &x) {
    if(x >= 'A' && x <= 'Z') return (char) x - R;
    return x;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a,b;int n;getline(cin,a);n = stoi(a);
    while(n--) {
        unordered_map<int,int>ma;
        unordered_map<int,int>mb;
        getline(cin,a);getline(cin,b);
        for(char &i : a) {
            if(isalpha(i)) {
                ma[lower(i)]++;
            }
        }
        for(char &i : b) {
            if(isalpha(i)) {
                mb[lower(i)]++;
            }
        }
        if(ma == mb) {
            cout<<"1\n";
            continue;
        }
        cout<<"0\n";
    }
    return 0;
}
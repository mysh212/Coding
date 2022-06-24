// Author : ysh
// 06/17/2022 Fri  6:33:16.09
#include<bits/stdc++.h>
using namespace std;
inline bool pt(bool x,int y,int z,string a,string b) {
    // cout<<a<<" "<<b<<" "<<y<<" "<<z<<" "<<(int) x<<"\n";
    return x;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while(cin>>n) {
        vector<string>f(n);
        for(string &i : f) {
            cin>>i;
        }
        sort(f.begin(),f.end(),[] (string a,string b) {
            bool c = 0;
            if(a == b) return true;
            if(a.size() > b.size()) {
                swap(a,b);
                c = 1;
            }
            int i = 0,j = a.size();
            string tmp = a + b;
            int n = tmp.size();
            while(n--) {
                if(tmp[i] != tmp[j]) return (bool) (c xor (tmp[i] >= tmp[j]));
                i++;j++;
                if(i >= tmp.size()) i = i % tmp.size();
                if(j >= tmp.size()) j = j % tmp.size();
            }
            return true;
        });
        for(string i : f) {
            cout<<i;
        }
        cout<<"\n";
    }
    return 0;
}
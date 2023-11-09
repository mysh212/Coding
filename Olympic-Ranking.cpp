// Author : ysh
// 2023/09/03 Sun 13:35:36
// https://codeforces.com/gym/103373/problem/A
#include<bits/stdc++.h>
using namespace std;
struct box{
    int a,b,c;
    string d;
    box(int a,int b,int c,string x):
        a(a), b(b), c(c), d(x) {};
    bool operator<(box &x) {
        if(a == x.a && b == x.b) return c < x.c;
        if(a == x.a) return b < x.b;
        return a < x.a;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<box>f;
    for(int i = 0;i<n;i++) {
        int a,b,c;cin>>a>>b>>c;
        string d;getline(cin,d);
        f.push_back(box(a,b,c,d));
    }

    cout<<max_element(f.begin(),f.end())->d.substr(1);
    return 0;
}
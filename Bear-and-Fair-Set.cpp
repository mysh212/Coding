// Author : ysh
// 2025/06/29 Sun 09:59:19
// https://codeforces.com/problemset/problem/628/F
#include<bits/stdc++.h>
using namespace std;
#include<slow>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;cin>>a>>b>>c;
    vector<pair<int, int>>f(c);
    repo(&i, f) cin>>i;

    f.push_back({0, 0});
    f.push_back({b, a});
    sort(all(f));
    re(i, 1, c + 2) if(f.at(i).second - f.at(i - 1).second > f.at(i).first - f.at(i - 1).first || f.at(i).second < f.at(i - 1).second) return cout<<"unfair", 0;
    
    cout<<"fair";
    return 0;
}
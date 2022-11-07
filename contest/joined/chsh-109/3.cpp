// Author : ysh
// 11/06/2022 Sun 13:52:18.56
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;cin>>a>>b>>c;
    vector<vector<int>>f(a);
    for(int i = 1;i<a;i++) {
        int a,b;cin>>a>>b;
        f.at(a).push_back(b);
        f.at(b).push_back(a);
    }
    function<int(int,int)> check = [&] (int last,int x) {
        int ans = 1;
        for(int &i : f.at(x)) {
            if(i != last) ans = ans + check(x,i);
        }
        return ans;
    };
    vector<int>mark;
    for(int &i : f.at(c)) {
        mark.push_back(check(c,i));
    }
    sort(mark.begin(),mark.end());
    for(int &i : mark) cout<<i<<" ";
    return 0;
}
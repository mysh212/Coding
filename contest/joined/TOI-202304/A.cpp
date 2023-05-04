// Author : ysh
// 04/25/2023 Tue 10:02:43.14
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<vector<int>>f(a);
    for(int i = 0;i<b;i++) {
        int a,b;cin>>a>>b;
        a--;b--;
        f.at(a).push_back(b);
        f.at(b).push_back(a);
    }
    
    bool c = 1;
    vector<bool>mark(a),color(a);
    function<pair<int,int>(int,bool)> check = [&] (int a,bool b) {
        if(mark.at(a) && color.at(a) != b) cout<<0,exit(0); 
        if(mark.at(a)) return make_pair(0,0);
        if(!mark.at(a)) mark.at(a) = 1,color.at(a) = b;
        pair<int,int>now = {1,0};
        for(int &i : f.at(a)) {
            pair<int,int> tmp = check(i,!b);
            now.second = now.second + tmp.first;
            now.first = now.first + tmp.second;
        }
        return now;
    };
    
    int ans = 0;
    for(int i = 0;i<a;i++) {
        if(!mark.at(i)) {
            color = vector<bool>(a);
            auto tmp = check(i,0);
            ans = ans + max(tmp.first,tmp.second);
        }
    }
    cout<<ans;
    return 0;
}
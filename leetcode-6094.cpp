// Author : ysh
// 06/12/2022 Sun 11:34:12.00
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<string>ideas = {"coffee","donuts","time","toffee"};
    int n = ideas.size();
    set<string>s,t;
    s.insert(ideas.begin(),ideas.end());
    int ans = 0;
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n;j++) {
            cerr<<i<<" "<<j<<"\n";
            if(i == j) continue;
            string a,b;
            a = ideas[i].substr(1);
            b = ideas[j].substr(1);
            a = ideas[j].substr(0,1) + a;
            b = ideas[i].substr(0,1) + b;
            //cerr<<a<<"\n";
            //cerr<<b<<"\n";
            if(s.find(a) == s.end() && s.find(b) == s.end() && t.find(a + " " + b) == t.end()) {
                t.insert(a + " " + b);
                cerr<<i<<" "<<j<<"\n";
                cerr<<a<<" "<<b<<"\n";
                ans++;
            }
            // s.insert(a);
            // s.insert(b);
        }
    }
    return ans;
}
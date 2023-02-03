// Author : ysh
// 02/03/2023 Fri  9:28:43.47
#include<bits/stdc++.h>
using namespace std;
vector<int> encoding(vector<int>&f) {
    map<int,int>m;
    int n = f.size();
    for(int i = 0;i<n;i++) {
        m.insert({f.at(i),i});
    }
    vector<int>v;
    for(auto i : m) {
        v.push_back(i.second);
    }
    return v;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n);
    map<int,int>m;
    for(int &i : f) {
        cin>>i;
    }
    f = encoding(f);
    for(int i = 0;i<n;i++) {
        m.insert({f.at(i),i});
    }
    int now;
    while(cin>>now) {
        vector<int>v({now});
        for(int i = 1;i<n;i++) {
            int tmp;cin>>tmp;
            v.push_back(tmp);
        }
        v = encoding(v);
        f = vector<int>();
        for(int &tmp : v) {
            tmp = m.find(tmp)->second;
            auto found = lower_bound(f.begin(),f.end(),tmp);
            if(found == f.end()) f.push_back(tmp);
            else *found = tmp;
        }
        cout<<f.size()<<"\n";
    }
    return 0;
}
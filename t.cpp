// Author : ysh
// 03/16/2023 Thu 19:44:19.98
#include<bits/stdc++.h>
using namespace std;
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    long long a,b;cout<<"> Input the number of students and groups in the class,seperate with ' ','<Enter>' or '<Tab>':";cin>>a>>b;
    vector<pair<string,long long>>f(a);
    cout<<"> Input the identify of students and their grades, enter them one by one.\ne.g.\nAmber 100\nAlex 99\n\n";
    for(auto &i : f) {
        cin>>i.first>>i.second;
        cout<<"> Data added: "<<i.first<<" "<<i.second<<"\n";
    }
    sort(f.begin(),f.end(),[] (pair<string,long long>&a,pair<string,long long>&b) {
        return a.second > b.second;
    });
    int t = 0;
    vector<vector<string>>v(b);
    for(pair<string,long long> &i : f) {
        v.at(t++).push_back(i.first);
        if(t == b) t = 0;
    }
    for(int i = 0;i<b;i++) {
        cout<<"Group #"<<i<<": ";
        for(string &i : v.at(i)) {
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
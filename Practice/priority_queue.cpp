// Author : ysh
// 01/27/2022 Thu 16:30:57.32
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>f;
    f.push({3,9});
    f.push({3,9});
    f.push({1,4});
    f.push({6,5});
    while(!f.empty()) {
        auto now = f.top();
        cout<<now.first<<" "<<now.second<<"\n";
        f.pop();
    }
}
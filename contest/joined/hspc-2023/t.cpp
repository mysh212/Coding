// Author : ysh
// 04/09/2023 Sun 14:22:45.68
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    priority_queue<pair<int,int>>q;
    q.emplace(0,1);
    q.emplace(1,1);
    q.emplace(1,2);
    while(!q.empty()) {
        cout<<q.top().first<<" "<<q.top().second<<"\n";
        q.pop();
    }
    return 0;
}
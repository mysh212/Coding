// Author : ysh
// 05/31/2022 Tue  9:50:41.98
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    priority_queue<int,vector<int>,greater<int>>f;
    f.push(1);
    f.push(2);
    int n = f.top();f.pop();
    cout<<n<<" ";
    n = f.top();f.pop();
    cout<<n<<"\n";
    return 0;
}
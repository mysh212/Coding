// Author : ysh
// 2024/10/03 Thu 18:22:53
#include<bits/stdc++.h>
using namespace std;
#include<heap>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    srand(time(NULL));
    int n;cin>>n;
    
    vector<int>f(n);
    for(int &i : f) i = rand();

    heap<int, less<int>>t;
    for(int &i : f) t.push(i);

    f = vector<int>(0);
    while(!t.empty()) {
        f.push_back(t.top());
        cerr<<t.top()<<" ";
        t.pop();
    }

    assert(is_sorted(f.rbegin(),f.rend()));
    return 0;
}
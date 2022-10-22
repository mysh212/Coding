#include<bits/stdc++.h>
using namespace std;
int main() {
    int a,b;cin>>a>>b;
    vector<vector<int>>f(a);
    int c[a] = {};
    for(int i = 0;i<b;i++) {
        int a,b;cin>>a>>b;
        a--;b--;
        c[b]++;
        f.at(a).push_back(b);
    }
    queue<int>q;
    for(int i = 0;i<a;i++) {
        if(c[i] == 0) q.emplace(i);
    }
    vector<bool>mark(a);
    queue<int>ans;
    while(!q.empty()) {
        int now = q.front();q.pop();
        if(mark.at(now)) continue;
        mark.at(now) = 1;
        ans.push(now + 1);
        for(int &i : f.at(now)) {
            c[i]--;
            if(c[i] == 0) q.emplace(i);
        }
    }
    for(int i = 0;i<a;i++) {
        if(c[i] != 0) {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES\n";
    while(!ans.empty()) {
        cout<<ans.front()<<"\n";ans.pop();
    }
    return 0;
}

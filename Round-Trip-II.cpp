// Author : ysh
// 10/11/2022 Tue  9:20:43.98
// https://cses.fi/problemset/task/1678
#include<bits/stdc++.h>
using namespace std;
vector<int>mark;
bitset<(int) 1e5>mk;
vector<int>re;
vector<vector<int>>f;
bool check(int x,int r = 1) {
    if(mk.test(x) && mark.at(x) == 0) return 0;
    if(mark.at(x) != 0) {
        if(r - mark.at(x) >= 2) {
            re.push_back(x);
            return 1;
        }
        return 0;
    }
    mk.set(x);
    mark.at(x) = r;
    for(int &i : f.at(x)) {
        if(check(i,r + 1)) {
            re.push_back(x);
            return 1;
        }
    }
    // mk.reset(x);
    mark.at(x) = 0;
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    mark.resize(a);
    f.resize(a);
    int to[a] = {};
    for(int i = 0;i<b;i++) {
        int a,b;cin>>a>>b;
        a--;b--;
        f.at(a).push_back(b);
        to[b]++;
    }
    // queue<int>ans;
    for(int i = 0;i<a;i++) {
        if((!mk.test(i)) && check(i)) {
            // printf("check(%d) return %d\n",i,1);
            // for(int i : re) cout<<i<<" ";
            // cout<<"\n";
            int tmp = re.front();
            while(re.back() != tmp) {
                re.pop_back();
            }
            cout<<re.size()<<"\n";
            while(!re.empty()) {
                cout<<re.back() + 1<<" ";re.pop_back();
                // cout<<ans.front() + 1<<" ";ans.pop();
            }
            return 0;
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}
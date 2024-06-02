// Author : ysh
// 2024/04/10 Wed 21:32:15
#include<bits/stdc++.h>
using namespace std;
#include<slow>
    #undef nl
struct tree{
    #define left(i) ((i << 1))
    #define right(i) ((i << 1) | 1)
    vector<int>f;
    int n;

    tree(int n):
        n(n), f(n << 2) {};

    void add(int l,int r,int t = 1,int nl = -1,int nr = -1) {
        if(l < r) return;
        if(nl == -1 && nr == -1) nl = 0,nr = n - 1;
        if(nl >= l && nr <= r) return f.at(t) += (nr - nl + 1),void();
        if(nl > r || nr < l) return;

        int mid = (nl + nr) >> 1;
        add(l,r,left(t),nl,mid);
        add(l,r,right(t),mid + 1,nr);
        return;
    }

    int sum(int t = 1,int nl = -1,int nr = -1) {
        if(nl == -1 && nr == -1) nl = 0,nr = n - 1;
        if(nl == nr) return f.at(t);

        int mid = (nl + nr) >> 1;
        return sum(left(t),nl,mid) + sum(right(t),mid  + 1,nr) + f.at(t);
    }
};

int offline(vector<pair<int,int>>&f) {
    vector<int>tmp;
    for(auto &i : f) tmp.push_back(i.first),tmp.push_back(i.second);
    sort(tmp.begin(),tmp.end());
    tmp.resize(unique(tmp.begin(),tmp.end()) - tmp.begin());

    for(auto &i : f) {
        i.first = lower_bound(tmp.begin(),tmp.end(),i.first) - tmp.begin();
        i.second = lower_bound(tmp.begin(),tmp.end(),i.second) - tmp.begin();
    }

    return tmp.size();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<pair<int,int>>f(n);
    for(auto &i : f) cin>>i.first>>i.second;

    int m = offline(f);

    tree t(m);
    for(auto &i : f) t.add(i.first,i.second - 1);
    cout<<t.sum();
    return 0;
}
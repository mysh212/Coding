// Author : ysh
// 2023/10/10 Tue 19:18:45
// https://codeforces.com/problemset/problem/1691/E
#include<bits/stdc++.h>
using namespace std;
struct mgr{
    vector<int>color;
    int n;

    mgr(int x = 0):
        n(x), color(x) {
            iota(color.begin(),color.end(),0);
        }
    
    void mg(int a,int b) {
        color.at(ff(a)) = ff(b);
        return;
    }

    int ff(int x) {
        if(color.at(x) == x) return x;
        return color.at(x) = ff(color.at(x));
    }

    size_t size() {
        vector<int>v;
        for(int i = 0;i<n;i++) {
            v.push_back(ff(i));
        }
        sort(v.begin(),v.end());
        v.resize(unique(v.begin(),v.end()) - v.begin());
        return v.size();
    }

    void print() {
        for(int i = 0;i<n;i++) {
            cout<<ff(i)<<" ";
        }
        cout<<"\n";
        return;
    }
};
struct box{
    int first,second,x;
    box(int first = 0,int second = 0,int x = 0):
        first(first), second(second), x(x) {};
    bool operator<(const box &a) const {
        if(first == a.first) return second < a.second;
        return first < a.first;
    }
};
int offline(vector<box>&f) {
    vector<int>v;
    for(auto &i : f) {
        v.push_back(i.first);
        v.push_back(i.second);
    }
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end()) - v.begin());
    for(auto &i : f) {
        i.first = int(lower_bound(v.begin(),v.end(),i.first) - v.begin());
        i.second = int(lower_bound(v.begin(),v.end(),i.second) - v.begin());
    }
    return v.size();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        vector<box>f(n);
        for(auto &i : f) {
            cin>>i.x>>i.first>>i.second;
        }
        sort(f.begin(),f.end());
        int m = offline(f);
        // for(auto &i : f) {
        //     cout<<i.first<<" "<<i.second<<" "<<i.x<<"\n";
        // }

        mgr t(n);
        int l,r;l = r = -1;
        int ll,rr;ll = rr = -1;
        int now = 0;
        for(auto &i : f) {
            if(i.x) {
                if(i.first <= ll) t.mg(l,now);
                if(r == -1 || i.second > rr) rr = i.second,r = now;
            } else {
                if(i.first <= rr) t.mg(r,now);
                if(l == -1 || i.second > ll) ll = i.second,l = now;
            }
            cout<<t.size()<<"\n";
            now++;
        }
        // t.print();

        cout<<t.size()<<"\n";
    }
    return 0;
}
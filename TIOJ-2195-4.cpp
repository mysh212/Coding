// Author : ysh
// 02/10/2023 Fri 23:29:23.64
// https://tioj.ck.tp.edu.tw/problems/2195
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a;cin>>a;
    map<int,int>m;
    for(int i = 0;i<a;i++) {
        int tmp;cin>>tmp;
        m[tmp] = i;
    }
    vector<int>f(a),down(a);
    for(int i = 0;i<a;i++) {
        cin>>down.at(i);
        f.at(m[down.at(i)]) = i;
    }

    vector<int>v;
    vector<array<int,3>>mark;
    reverse(f.begin(),f.end());
    for(int &i : f) {
        i = -i;
        auto found = lower_bound(v.begin(),v.end(),i);
        mark.push_back({(int) (found - v.begin()),down.at(-i),-i});
        if(found == v.end()) v.push_back(i);
        else *found = i;
    }

    sort(mark.begin(),mark.end(),[] (array<int,3>&a,array<int,3>&b) {
        if(a[0] == b[0] && a[1] == b[1]) return a[2] < b[2];
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] > b[0];
    });
    int mmax = -1;
    int n = v.size() - 1;
    for(auto &i : mark) {
        cerr<<i[0]<<" "<<i[1]<<" "<<i[2]<<"\n";
        if(i[2] > mmax && i[0] == n) {
            mmax = i[2];
            n--;
            cout<<i[1]<<" ";
        }
    }
    return 0;
}
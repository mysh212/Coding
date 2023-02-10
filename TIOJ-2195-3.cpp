// Author : ysh
// 02/10/2023 Fri  9:43:19.14
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
    vector<vector<pair<int,int>>>mark;
    vector<int>start;
    vector<int>re(a);
    for(int &i : f) {
    debug(mark);
        auto found = lower_bound(v.begin(),v.end(),i);
        // if(found == prev(v.end())) start.push_back(i);
        if(found == v.end()) {
            if(found == v.begin()) { 
                re.at(i) = -1;
                mark.push_back({{down.at(i),i}});
                start.push_back(i);
                v.push_back(i);
                continue;
            }
            re.at(i) = prev(lower_bound(mark.at(found - v.begin() - 1).rbegin(),mark.at(found - v.begin() - 1).rend(),i,[] (pair<int,int>&a,int b) {
                return a.second < b;
            }))->second;
            mark.push_back({{down.at(i),i}});
            start.clear();
            start.push_back(i);
            v.push_back(i);
            continue;
        } else {
            *found = i;
            if(found - v.begin() == v.size() - 1) start.push_back(i);
            if(found == v.begin()) {
                re.at(i) = -1;
                // if(down.at(i) > mark.at(found - v.begin()).first) mark.at(found - v.begin()) = {down.at(i),i};
                while(!mark.at(found - v.begin()).empty() && mark.at(found - v.begin()).back().first < down.at(i)) {
                    mark.at(found - v.begin()).pop_back();
                }
                mark.at(found - v.begin()).push_back({down.at(i),i});
                continue;
            }
            // re.at(i) = mark.at(found - v.begin() - 1).second;
            re.at(i) = prev(lower_bound(mark.at(found - v.begin() - 1).rbegin(),mark.at(found - v.begin() - 1).rend(),i,[] (pair<int,int>&a,int b) {
                return a.second < b;
            }))->second;
            // if(down.at(i) > mark.at(found - v.begin()).first) mark.at(found - v.begin()) = {down.at(i),i};
            while(!mark.at(found - v.begin()).empty() && mark.at(found - v.begin()).back().first < down.at(i)) {
                mark.at(found - v.begin()).pop_back();
            }
            mark.at(found - v.begin()).push_back({down.at(i),i});
            continue;
        }
    }
    vector<vector<int>>ans;
    for(int i : start) {
        vector<int>tmp;
        while(i != -1) {
            tmp.push_back(down.at(i));
            i = re.at(i);
        }
        reverse(tmp.begin(),tmp.end());
        ans.push_back(tmp);
    }
    sort(ans.begin(),ans.end());
    debug(start,ans);
    for(int &i : ans.back()) cout<<i<<" ";
    return 0;
}
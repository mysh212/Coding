// Author : ysh
// 06/12/2022 Sun 10:12:21.47
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<C:\Users\Public\debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int>nums;
    string a;
    getline(cin,a);
    stringstream s;
    s << a;
    while(s >> a) {
        nums.push_back(stoi(a));
    }
    debug(nums);
        //int n = nums.size();
        //int tmp = nums[0];
        //int ans = 0;
        vector<int>::iterator t;
        t = unique(nums.begin(),nums.end());
        nums.resize(t - nums.begin());
    debug(nums);
        return t - nums.begin();
}
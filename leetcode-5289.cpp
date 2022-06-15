// Author : ysh
// 06/12/2022 Sun 11:20:19.10
// NF
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int>cookies{8,15,10,20,8};
    // 8 8 10 15 20
    int k = 2;
        sort(cookies.begin(),cookies.end());
        int sig = 0;
        for(int i : cookies) sig += i;
        int n = (sig % k == 0 ? sig / k : (sig / k) + 1);
        int l,r;l = r = 0;
        sig = 0;
        int mmin = INT_MAX;
        int len = cookies.size() - 1;
        while(1) {
            if(sig > n) {
                mmin = min(mmin,sig);
            }
            if(sig == n) {
                return sig;
            }
            if(sig < n) {
                if(r == len) {
                    return mmin;
                }
                r++;
                sig += cookies[r];
            }
            if(sig > n) {
                l++;
                sig -= cookies[l - 1];
            }
        }
}
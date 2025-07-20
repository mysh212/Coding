// Author : ysh
// 2025/04/10 Thu 11:03:04
// https://codeforces.com/contest/2084/problem/C
#include<bits/stdc++.h>
using namespace std;
#include<slow>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    re(n) {
        int n;cin>>n;
        
        vc<pair<int,int>>f(n);
        repo(&i, f) cin>>i.first, i.first--;
        repo(&i, f) cin>>i.second, i.second--;

        vc<pair<int,int>>mark(n);
        re(i, n) mark.at(f.at(i).first).first = i, mark.at(f.at(i).second).second = i;

        #define update(i) (mark.at(f.at(i).first).first = i, mark.at(f.at(i).second).second = i)

        int same = 0, p = -1;
        repo(&i, f) if(i.first == i.second) same++, p = i.first;

        vc<pair<int,int>>ans;
        int m = (n >> 1) - (n & 1);
        if(((n & 1) && same > 1) || (!(n & 1) && same != 0)) goto no;
        re(i, n) if(!(f.at(mark.at(f.at(i).second).first).second == f.at(i).first)) goto no;
        debug(f);
        debug(mark);

        yes:
            if(same != 0) {
                int target = (n >> 1);
                int ot = mark.at(p).first;
                if(ot != target) {
                    // outs(ot + 1);outl(target + 1);
                    ans.push_back({ot, target});
                    swap(f.at(ot), f.at(target));
                    update(ot);
                    update(target);
                }
            }
            re(i, m) {
                // if(n & 1 && i == (m)) continue;
                int target = (n - 1) - i;
                if(target < i) break;
                int ot = mark.at(f.at(i).first).second;
                if(ot == target) continue;
                swap(f.at(ot), f.at(target));
                update(ot);
                update(target);
                // outs(ot + 1);outl(target + 1);
                ans.push_back({ot, target});
            }
            outl(ans.size());
            repo(&i, ans) outs(i.first + 1), outl(i.second + 1);
            continue;
        no:
            outt(-1);nl;
    }
}
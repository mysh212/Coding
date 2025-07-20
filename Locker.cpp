// Author : ysh
// 2025/04/20 Sun 21:35:27
// https://vjudge.net/problem/UVA-1631
// NF
#include<bits/stdc++.h>
using namespace std;
#include<slow>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a,b;
    while(cin>>a>>b) {
        int n = a.size();
        vector<int>f(n);

        re(i, n) f.at(i) = b.at(i) - a.at(i);
        repo(&i, f) if(i < 0) i += 10;

        vc<vc<int>>mark(n, vc<int>(3, INT_MAX));
        re(i, n) {
            int last = f.at(i);
            re(j, 1, 3) {
                if(i - j < 0) break;
                
                int aans = INT_MAX;
                re(ans, 0, 10) {
                    int now = 0;
                    re(k, j + 1) now += min(abs(f.at(i - k) - ans), 10 - abs(f.at(i - k) - ans));
                    aans = min({min(ans, 10 - ans) + now, aans});
                }

                mark.at(i).at(j) = (i == j ? 0 : mark.at(i - j - 1).at(2)) + aans;
            }
            mark.at(i).at(0) = (i == 0 ? 0 : mark.at(i - 1).back()) + min(10 - f.at(i), f.at(i));
            re(j, 1, 3) mark.at(i).at(j) = min(mark.at(i).at(j), mark.at(i).at(j - 1));
        }
        
        repo(&i, mark) outl(i);
        outl(mark.back().back());
    }
    return 0;
}
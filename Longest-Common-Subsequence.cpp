// Author : ysh
// 2025/04/12 Sat 23:11:09
// https://vjudge.net/problem/UVA-10405
#include<bits/stdc++.h>
using namespace std;
#include<slow>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a,b;
    while(getline(cin, a) && getline(cin, b)) {
        int aa = a.size();
        int bb = b.size();

        vc<vc<int>>f(2, vc<int>(bb + 1));

        re(i, 1, aa + 1) re(j, 1, bb + 1) {
            int p = i & 1;
            f.at(p).at(j) = max(f.at(!p).at(j), f.at(p).at(j - 1));
            if(a.at(i - 1) == b.at(j - 1)) f.at(p).at(j) = max(f.at(p).at(j), f.at(!p).at(j - 1) + 1);
        }

        outl(f.at((aa & 1)).at(bb));
    }
    return 0;
}
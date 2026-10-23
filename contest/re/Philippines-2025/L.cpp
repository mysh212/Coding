// Author : ysh
// 2026/10/22 Thu 15:09:52
#include<bits/stdc++.h>
using namespace std;
#include<slow>
#define R 1006903069
#define int int64_t
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

	int n;cin>>n;

	map<pair<int, int>, int>m;

	int a, b;cin>>a;
	map<pair<int, int>, int>l;
	re(a) {
		int a, b, c;cin>>a>>b>>c;
		l.insert({{a, b}, c});
	}

	vc<int>ans(n);
	cin>>b;
	re(b) {
		int a, b, c;cin>>a>>b>>c;
		auto found = l.find({b, a});
		if(found == l.end()) continue;
		ans.at(b - 1) += found -> second * c;
		ans.at(b - 1) %= R;
	}

	int aans = 0;
	repo(&i, ans) aans += i, aans %= R;

	out(aans);
	return 0;
}

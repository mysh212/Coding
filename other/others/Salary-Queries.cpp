/**
 *		author:	wy
 *		created: Tue, 16 Aug 2022 13:45:22 GMT
**/
#include <bits/stdc++.h>
 
using namespace std;
 
template <typename T>
class fenwick {
 public:
	vector<T> fenw;
	int n;
 
	fenwick(int _n) : n(_n) {
		fenw.resize(n);
	}
 
	void modify(int x, T v) {
		while (x < n) {
			fenw[x] += v;
			x |= (x + 1);
		}
	}
 
	T get(int x) {
		T v{};
		while (x >= 0) {
			v += fenw[x];
			x = (x & (x + 1)) - 1;
		}
		return v;
	}
};
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int> p(n);
	vector<int> xs;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		xs.push_back(p[i]);
	}
	vector<array<int, 3>> qs;
	for (int i = 0; i < q; i++) {
		char op;
		int a, b, c;
		cin >> op >> b >> c;
		a = (op == '!' ? 0 : 1);
		if (a == 0) {
			xs.push_back(c);
		}
		qs.push_back({a, b, c});
	}
	sort(xs.begin(), xs.end());
	xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
	fenwick<int> fenw(xs.size());
	for (int i = 0; i < n; i++) {
		p[i] = (int) (lower_bound(xs.begin(), xs.end(), p[i]) - xs.begin());
		fenw.modify(p[i], +1);
	}
	for (int i = 0; i < q; i++) {
		int a = qs[i][0];
		int b = qs[i][1];
		int c = qs[i][2];
		if (a == 0) {
			b -= 1;
			fenw.modify(p[b], -1);
			p[b] = (int) (lower_bound(xs.begin(), xs.end(), c) - xs.begin());
			fenw.modify(p[b], +1);
		} else {
			b = (int) (lower_bound(xs.begin(), xs.end(), b) - xs.begin() - 1);
			c = (int) (upper_bound(xs.begin(), xs.end(), c) - xs.begin() - 1);
			cout << fenw.get(c) - (b >= 0 ? fenw.get(b) : 0) << '\n';
		}
	}
	return 0;
}
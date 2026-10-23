// Author : ysh
// 2026/10/22 Thu 15:31:12
#include<bits/stdc++.h>
using namespace std;
static constexpr int N = 1e7+5;
const int mod = 104206969;
bitset<N + 1>s;
vector<int>prime;
vector<int64_t>prefix;

vector<int64_t> fp, fprefix;

#define int int64_t

inline void init() {
	s.set(0);
	s.set(1);
	for(int i = 2; i <= N; i++) {
		if(s.test(i)) continue;
		prime.push_back(i);
		for(int j = i * i; j <= N; j += i) s.set(j);
	}

	prefix = vector<int64_t>(prime.begin(), prime.end());
	int last = 0;
	for(int &i : prefix) i = last += i;

	return;
}

inline bool isprime(int x) {
	return !s.test(x);
}

void init2() {
	for(int i = 0; i < prime.size()-1; i++) {
		if(prime[i] + 2 == prime[i+1]) {
			fp.push_back(prime[i]);
		}
	}
	fprefix = vector<int64_t>(fp.begin(), fp.end());
	int last = 0;
	for(auto &i : fprefix) i = last += i;
}

inline int range(int l, int r) {
	auto ll = lower_bound(prime.begin(), prime.end(), l);
	auto rr = upper_bound(prime.begin(), prime.end(), r);
	return rr - ll;
}
inline int frange(int l, int r) {
	auto ll = lower_bound(fp.begin(), fp.end(), l);
	auto rr = upper_bound(fp.begin(), fp.end(), r);
	return rr - ll;
}

inline int sum(int x) {
	if(x < 2) return 0;

	auto found = upper_bound(prime.begin(), prime.end(), x);
	int pre = (found - 1) - prime.begin();

	return prefix.at(pre);
}
inline int fsum(int x) {
	if(x <= 2) return 0;

	auto found = upper_bound(fp.begin(), fp.end(), x);
	int pre = (found - 1) - fp.begin();

	return fprefix.at(pre);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

	init();
	init2();
	int T = 1;
	cin >> T;
	while(T--) {
		int n,k;
		cin >> n >> k;
		if(k == 0) { cout<<1<<'\n';continue; }
		if(k == 1) { cout<<n<<'\n';continue; }
		if(k == 2) {
			int ans = n * range(1,n);
			ans += mod - sum(n);
			ans = ((ans % mod) + mod)%mod;
			cout << ans << '\n';
			continue;
		}
		if(k == 3) {
			int ans = (frange(1,n-2) % mod) * (n-2) % mod;
			ans += mod - fsum(n-2);
			ans = ((ans % mod) + mod) % mod;
			cout << ans*2%mod << '\n';
			continue;
		}
		cout << 0 << '\n';
		continue;
	}
}

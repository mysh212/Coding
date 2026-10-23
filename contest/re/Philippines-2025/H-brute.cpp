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

#include<slow>
#define int int64_t

inline void init() {
	s.set(0);
	s.set(1);
	for(int i = 2; i <= N; i++) {
//		if(s.test(i)) continue;
		if(!s.test(i)) prime.push_back(i);
		for(int j = i * i; j <= N; j += i) s.set(j);
	}

	prefix = vector<int64_t>(prime.begin(), prime.end());
	int last = 0;
	for(int &i : prefix) i = last += i;

//	re(i, 100) outs(prime.at(i));

	return;
}

inline bool isprime(int x) {
	return !s.test(x);
}

signed main() {
	init();
	int n;cin>>n;
	while(n--) {
		int a, b; cin>>a>>b;

		if(b > 3) {
			cout<<0<<"\n";
			continue;
		}
		if(b == 3) {
			int ans = 0;
			re(i, a) re(j, i) re(k, j) {
				if(isprime(i - j) && isprime(i - k) && isprime(j - k)) ans++;
			}
			outl(ans);
			continue;
		}
		if(b == 2) {
			int ans = 0;
			re(i, a) re(j, i) {
				if(isprime(i - j)) ans++;
			}
			outl(ans);
			continue;
		}
		if(b == 1) {
			outl(a);
			continue;
		}
		if(b == 0) outl(0);
	}
	return 0;
}

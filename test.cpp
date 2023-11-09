#
void solve() {
  LL(N);
  VEC(string, S, N);
  ll ans = 0;
  vv(ll, cnt, 6, 50);
  FORE(s, S) cnt[len(s)][get(s)]++;
  FOR(l, 2, 11, 2) {
    FORE(s, S) if (len(s) > l / 2 && len(s) < l) {
      ll d = l - len(s);
      ll t1 = -get(s.substr(l / 2)) + get(s.substr(0, l / 2));
      ll t2 = -get(s.substr(0, len(s) - l / 2)) + get(s.substr(len(s) - l / 2));
      // t1 = abs(t1); t2 = abs(t2);
      if (t1 >= 0) ans += cnt[d][t1];
      if (t2 >= 0) ans += cnt[d][t2];
      // print(l, s, d, t1, t2);
    }
    vi prefix(50);
    FORE(s, S) if (len(s) == l / 2) {
      prefix[get(s)]++;
      ans += 2 * prefix[get(s)] - 1;
    }
    // print(l, ans);
  }  
  print(ans);
}
 
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll T = 1;
  FOR(T) solve();
  return 0;
}
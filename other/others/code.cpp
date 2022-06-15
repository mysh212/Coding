/**
 *    author:  willy
 *    created: Mon, 06 Jun 2022 01:03:44 GMT
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "C:\Users\Public\debug.h"
#else
#define debug(...) 42
#endif

const int inf = (int) 1.01e9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<int>> dist(2, vector<int>(n));
  for (int qq = 0; qq < 2; qq++) {
    map<int, vector<int>> mp;
    if (qq == 0) {
      mp[-inf].push_back(0);
    }
    for (int i = 0; i < n; i++) {
      mp[a[i]].push_back(i + 1);
      // debug(qq, i, a[i], mp);
      if (mp.find(a[i]) == mp.begin()) {
        dist[qq][i] = n - i;
      } else {
        auto ids = *prev(mp.find(a[i]));
        dist[qq][i] = (i + 1) - ids.second.back();
      }
    }
    reverse(a.begin(), a.end());
  }
  reverse(dist[1].begin(), dist[1].end());
  // debug(dist[0]);
  // debug(dist[1]);
  for (int i = 0; i < n; i++) {
    cout << min(dist[0][i], dist[1][i]) << " \n"[i == n - 1];
  }
  return 0;
}
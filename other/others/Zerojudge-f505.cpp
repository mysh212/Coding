/**
 *    author:  willy
 *    created: Fri, 17 Sep 2021 15:05:05 GMT
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 234;

int cap[3];
int ans[N];
int dist[N][N];
bool mark[N][N];

void init() {
  memset(ans, -1, sizeof(ans));
  memset(dist, -1, sizeof(dist));
  memset(mark, false, sizeof(mark));
}

struct node {
  array<int, 3> v;
  int dist;

  inline bool operator < (const node &rhs) const {
    return dist > rhs.dist;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    init();
    int d;
    cin >> cap[0] >> cap[1] >> cap[2] >> d;
    priority_queue<node> pq;
    pq.push({{0, 0, cap[2]}, 0});
    while (!pq.empty()) {
      node u = pq.top();
      pq.pop();
      if (mark[u.v[0]][u.v[1]]) {
        continue;
      }
      mark[u.v[0]][u.v[1]] = true;
      for (int i = 0; i < 3; i++) {
        int d = u.v[i];
        if (ans[d] < 0 || u.dist < ans[d]) {
          ans[d] = u.dist;
        }
      }
      if (ans[d] >= 0) {
        break;
      }
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          if (i == j) {
            continue;
          }
          int amount = 0;
          if (cap[j] < u.v[i] + u.v[j]) {
            amount += cap[j] - u.v[j];
          } else {
            amount += u.v[i];
          }
          node u2 = u;
          u2.dist = u.dist + amount;
          u2.v[i] -= amount;
          u2.v[j] += amount;
          int &D = dist[u2.v[0]][u2.v[1]];
          if (D < 0 || u2.dist < D) {
            D = u2.dist;
            pq.push(u2);
          }
        }
      }
    }
    while (d >= 0) {
      if (ans[d] >= 0) {
        cout << ans[d] << " " << d << '\n';
        break;
      }
      d -= 1;
    }
  }
  return 0;
}
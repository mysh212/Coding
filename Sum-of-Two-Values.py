# Author : ysh
# 2025/03/30 Sun 23:52:21
# https://cses.fi/problemset/task/1640
# TLE

import sys

input = sys.stdin.readline

a, b = [int(i) for i in input().split()]

pre = {}
t = 0
for i in [int(i) for i in input().split()]:
    ans = pre.get(b - i, None)
    # print(b - i, ans)
    if ans is not None:
        print(ans + 1, t + 1)
        quit()
    pre[i] = t
    t = t + 1

print('IMPOSSIBLE')
quit()
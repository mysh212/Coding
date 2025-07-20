# Author : ysh
# 2025/06/11 Wed 10:33:23
# https://atcoder.jp/contests/abc409/tasks/abc409_b
# NF

n = int(input())
f = [int(i) for i in input().split()]

f = sorted(f)

ans = 0
left = n
for i in f:
    if left >= i:
        ans = i
    else:
        ans = max(ans, left)
    left = left - 1

print(ans)
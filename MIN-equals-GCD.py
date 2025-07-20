# Author : ysh
# 2025/04/09 Wed 17:12:41
# https://codeforces.com/contest/2084/problem/B
from math import gcd

for _ in range(int(input())):
    n = int(input())
    f = sorted([int(i) for i in input().split()])

    now = -1
    ok = False
    for i in f[1:]:
        if i % f[0] == 0:
            now = gcd(now, i) if not now == -1 else i
    if now == f[0]:
        print('YES')
        continue

    last = f[0]
    for i in range(1, n):
        if last < f[i]:
            break
        if last == f[i]:
            ok = True
            break
        now = last
        for j in f[i + 1:]:
            if j % f[i] == 0:
                now = gcd(now, j)
        if now == f[i]:
            ok = True
            break
        last = gcd(last, f[i])
    
    print('YES' if ok else 'NO')
quit()
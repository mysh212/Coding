# Author : ysh
# 2024/05/03 Fri 20:40:37
# https://codeforces.com/contest/1968/problem/A
from math import gcd

for _ in range(int(input())):
    n = int(input())
    mmax = 0
    ans = 0
    for i in range(1,n):
        if gcd(i,n) + i > mmax:
            mmax = gcd(i,n) + i
            ans = i
    print(ans)
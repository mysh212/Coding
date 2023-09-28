# Author : ysh
# 2023/07/22 Sat 16:33:32
# https://codeforces.com/contest/1850/problem/E
from math import sqrt


for i in range(int(input())):
    a,b = [int(i) for i in input().split()]
    c,d = 0,0
    f = [int(i) for i in input().split()]
    b = b - sum([i * i for i in f])
    c,d = len(f),sum(f) << 1
    print(int((-d + sqrt(d * d + c * b * 4)) // (c * 2)) >> 1)
quit()
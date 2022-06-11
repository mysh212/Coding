# Author : ysh
# 05/31/2022 Tue  9:00:29.73
from numpy import gcd
a = int(input())
b = [int(i) for i in input().split()]
g = b[0]
for i in b:
    g = gcd(g,i)
for i in range(int(input())):
    a = int(input())
    if (a - 1115) % g == 0:
        print('YES')
    else:
        print('NO')
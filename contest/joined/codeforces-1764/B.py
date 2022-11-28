# Author : ysh
# 11/26/2022 Sat 22:29:08.83
from math import gcd


for i in range(int(input())):
    a = int(input())
    b = [int(i) for i in input().split()]
    c = b[0]
    for j in b:
        c = gcd(c,j)
    print(b[a - 1] // c)
quit()
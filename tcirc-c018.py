# Author : ysh
# 03/06/2023 Mon 12:32:14.45
# https://judge.tcirc.tw/ShowProblem?problemid=c018
from math import gcd
a = [int(i) for i in input().split()]
a[0],a[1] = a[0] // gcd(a[0],a[1]),a[1] // gcd(a[0],a[1])
print(a[1])
# Author : ysh
# 11/05/2022 Sat 13:56:58.85
from math import gcd


a = [int(i) for i in input().split()]
a.pop()
ans = a[0]
for i in a:
    ans = gcd(ans,i)
print(ans,end = ' ')
aans = ans
for i in a:
    tmp = gcd(aans,i)
    aans = aans * (i // tmp)
print(aans,end = '')
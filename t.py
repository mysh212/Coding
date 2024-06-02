# Author : ysh
# 2024/05/16 Thu 22:53:33
from math import ceil, log


for i in range(int(input())):
    n = int(input())
    f = [int(i) for i in input().split()]
    ans = 0
    last = -1
    for i in f:
        if last == -1:
            last = i
            continue
        if not (last <= i):
            pre = ceil((log(last / i,2)))
            ans += pre
            i = i << pre
        last = i
    print(ans)
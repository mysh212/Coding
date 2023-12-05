# Author : ysh
# 2023/12/01 Fri 21:30:24
# https://codeforces.com/problemset/problem/1604/A
for i in range(int(input())):
    n = int(input())
    ans = 0
    f = ([int(i) for i in input().split()])
    for i in f:
        ans = max(ans + 1,i)
    print(ans - len(f))
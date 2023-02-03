# Author : ysh
# 01/25/2023 Wed  8:47:58.82
# https://codeforces.com/contest/1792/problem/A
for i in range(int(input())):
    n = int(input())
    a = sorted([int(i) for i in input().split()])
    t = 0
    for j in a:
        if j == 1:
            t = t + 1
        if j > 1:
            break
    print(n - (t >> 1))
quit()

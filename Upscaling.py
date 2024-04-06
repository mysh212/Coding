# Author : ysh
# 2024/04/01 Mon 19:59:09
# https://codeforces.com/contest/1950/problem/B
for i in range(int(input())):
    n = int(input())
    for j in range(n << 1):
        for k in range(n << 1):
            jj = j >> 1
            kk = k >> 1
            print(['#','.'][(jj ^ kk) & 1],end = '')
        print('')
quit()
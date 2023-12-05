# Author : ysh
# 2023/12/05 Tue 20:41:19
# https://codeforces.com/problemset/problem/1891/A
for i in range(int(input())):
    n = int(input())
    f = [int(i) for i in input().split()]
    l = 0;r = 1;
    c = True
    while r <= n:
        for i in range(l + 1,r):
            if f[i] < f[i - 1]:
                c = False
        l = l << 1
        r = r << 1
        if l == 0: l = 1;
    for i in range(l + 1,n):
        if f[i] < f[i - 1]:
            c = False
    if c: print('YES')
    else: print('NO')
quit()
# Author : ysh
# 2024/02/05 Mon 21:57:24
# https://codeforces.com/contest/1428/problem/C
for i in range(int(input())):
    n = input()[::-1]
    a,b = 0,0
    ans = 0
    for j in n:
        if j == 'B':
            b = b + 1
        else:
            if b == 0: continue;
            b = b - 1
            ans = ans + 1
    ans = ans + (b >> 1)
    print(len(n) - (ans << 1))
quit()

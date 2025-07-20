# Author : ysh
# 2025/07/18 Fri 22:08:12
# https://www.luogu.com.cn/problem/P4000
import sys
sys.set_int_max_str_digits(30000000)

a, b = [int(input()) for _ in range(2)]

if a == 0:
    print(0)
    quit()

r = [[0, 1], [1, 1]]
l = [0, 1]

if a <= 2:
    print(1)
    quit()

def tm(l, r):
    ans = [[0 for _ in range(2)] for _ in range(2)]
    for i in range(2):
        for j in range(2):
            for k in range(2):
                ans[i][j] += l[i][k] * r[k][j]
                ans[i][j] %= b
    return ans

def fp(a, b: int):
    if b == 1: return a;

    now = fp(a, b >> 1)
    now = tm(now, now)
    if b & 1:
        return tm(now, a)
    else:
        return now
    
print(fp(r, a)[1][0])
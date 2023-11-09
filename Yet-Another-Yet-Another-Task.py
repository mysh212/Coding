# Author : ysh
# 2023/08/24 Thu 14:47:28
# https://codeforces.com/contest/1359/problem/D
n = int(input())
f = [int(i) for i in input().split()]

ans = 0
for i in range(31)[::-1]:
    mmin = 0
    now = 0
    sig = 0
    for j in f:
        if j > i:
            j = -1e9
        sig = sig + j
        mmin = min(sig,mmin)
        now = max(sig - mmin,now)
    ans = max(ans,now - i)

print(int(ans))
quit()
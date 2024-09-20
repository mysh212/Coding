# Author : ysh
# 2024/09/18 Wed 21:47:34
# https://judge.citrc.tw/problem/26-5
n = int(input())
ans,mmax = 0,n
while n != 0:
    if not (n & 1) or n == 1:
        n = n >> 1
    else:
        n = (n * 3) + 1
    ans = ans + 1
    mmax = max(mmax,n)

print(ans,mmax,sep = '\n')
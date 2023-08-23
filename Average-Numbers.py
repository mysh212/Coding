# Author : ysh
# 2023/08/14 Mon 12:18:02
# https://codeforces.com/contest/134/problem/A
n = int(input())
f = [int(i) for i in input().split()]
sig = sum(f)
ans = []
t = 1
for i in f:
    if i * n == sig:
        ans.append(t)
    t = t + 1

print(len(ans))
for i in ans:
    print(i,end = ' ')

quit()
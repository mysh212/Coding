# Author : ysh
# 2023/09/13 Wed 12:43:23
# https://codeforces.com/problemset/problem/1152/A
f = [[0,0],[0,0]]
a,b = [int(i) for i in input().split()]
for i in [int(i) for i in input().split()]:
    f[0][i & 1] = f[0][i & 1] + 1
for i in [int(i) for i in input().split()]:
    f[1][i & 1] = f[1][i & 1] + 1

print(min(f[0][0],f[1][1]) + min(f[1][0],f[0][1]))
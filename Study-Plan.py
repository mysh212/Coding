# Author : ysh
# 02/07/2023 Tue 15:54:02.52
# https://codeforces.com/group/H0qY3QmnOW/contest/425166/problem/F
n = input()
a = [int(i) for i in input().split()]
v = [[0 for i in range(int(n))] for j in range(2)]
for i in range(int(n)):
    if i == 0:
        v[1][0] = a[0]
        v[0][0] = 0
        continue
    if i == 1:
        v[1][1] = a[0] + a[1]
        v[0][1] = v[1][0]
        continue
    if i == 2:
        v[0][i] = max(v[1][i - 1],v[0][i - 1])
        v[1][i] = v[0][i - 2] + a[i - 1] + a[i]
        v[1][i] = max(v[1][i],v[0][i])
        continue
    v[0][i] = max(v[1][i - 1],v[0][i - 1])
    v[1][i] = max(v[0][i - 2] + a[i],v[0][i - 3] + a[i - 1] + a[i])
    v[1][i] = max(v[1][i],v[0][i])
# print(v)
print(max(v[1][int(n) - 1],v[0][int(n) - 1]))
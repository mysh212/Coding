# Author : ysh
# 06/05/2022 Sun  6:51:12.81
# https://192.168.193.20/contest/2/problem/023
a = int(input())
b = [[0,1], [0,1]]
print(1)
now = 1
for i in range(a):
    for j in range(now):
        if j == 0:
            b[now & 1].clear()
            b[now & 1].append(0)
            continue
        n = b[not (i & 1)][j] + b[not (i & 1)][j - 1]
        print(n,end = ' ')
        b[i & 1].append(n)
    now = now + 1
    print('')
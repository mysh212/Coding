# Author : ysh
# 2026/11/07 Sat 20:02:21
a, b = [int(i) for i in input().split()]
f = [*range(1, a + 1)]

for i in [int(i) for i in input().split()]:
    f[:i] = [-j for j in f[:i][::-1]]

for i in f:
    print(i)
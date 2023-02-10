# Author : ysh
# 02/10/2023 Fri 12:29:32.33
n = int(input())
a = sorted([int(i) for i in input().split()])[::-1]
for i in range(n):
    print(a[i],end = ' ')
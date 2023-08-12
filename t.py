# Author : ysh
# 2023/08/03 Thu 18:26:39
n = int(input())
a,b = 0,0
for i in range(n):
    f = [int(i) for i in input().split()]
    a = a + f[0]
    b = b + f[1]
print(a // n,b // n)
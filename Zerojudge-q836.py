# Author : ysh
# 2025/06/18 Wed 18:40:14
n = int(input())
a, b = [int(i) for i in input().split()]
c, d = [int(i) for i in input().split()]
now = 0
while n > 0:
    now += n
    if now % a == 0:
        n -= b
    if now % c == 0:
        n -= d
print(now)
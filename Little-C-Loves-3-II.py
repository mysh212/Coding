# Author : ysh
# 03/14/2023 Tue 11:20:05.75
# https://codeforces.com/problemset/problem/1034/B
a = [int(i) for i in input().split()]
if a[0] > a[1]:
    a[0],a[1] = a[1],a[0]

if a[0] == 2 and a[1] == 2:
    print(0)
    quit()
if a[0] == 2 and a[1] == 3:
    print(4)
    quit()
if a[0] == 2 and a[1] == 7:
    print(12)
    quit()
if a[0] == 1:
    print((a[1] // 6) * 6 + ((max(0,(a[1] % 6) - 3) << 1)))
    quit()
print(a[0] * a[1] - ((a[0] * a[1]) & 1))
quit()

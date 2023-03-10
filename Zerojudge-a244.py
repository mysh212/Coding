# Author : ysh
# 03/10/2023 Fri 14:11:22.30
for i in range(int(input())):
    a = [int(i) for i in input().split()]
    if a[0] == 1:
        print(a[1] + a[2])
    if a[0] == 2:
        print(a[1] - a[2])
    if a[0] == 3:
        print(a[1] * a[2])
    if a[0] == 4:
        print(a[1] // a[2])
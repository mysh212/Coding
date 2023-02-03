# Author : ysh
# 01/25/2023 Wed 19:31:57.76
# https://codeforces.com/contest/1792/problem/B
for i in range(int(input())):
    a = [int(i) for i in input().split()]
    print([1,a[0] + (min(a[1],a[2]) << 1) + min(a[0] + 1,abs(a[1] - a[2]) + a[3])][a[0] != 0])
quit()
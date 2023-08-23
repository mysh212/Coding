# Author : ysh
# 2023/08/14 Mon 13:20:34
# https://codeforces.com/contest/160/problem/C
a,b = [int(i) for i in input().split()]
f = sorted([int(i) for i in input().split()])

print(f[(b - 1) // a],f[(b - 1) % a])
quit()
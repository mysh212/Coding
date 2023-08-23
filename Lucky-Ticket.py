# Author : ysh
# 2023/08/14 Mon 09:58:53
# https://codeforces.com/contest/146/problem/A
n = int(input())
a = input()
c = True
for i in a:
    if i != '4' and i != '7':
        c = False
if sum([int(i) for i in a[:(n >> 1)]]) != sum([int(i) for i in a[(n >> 1):]]):
    c = False
print(['NO','YES'][c])
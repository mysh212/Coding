# Author : ysh
# 2023/08/09 Wed 18:14:14
# https://atcoder.jp/contests/abc309/tasks/abc309_a
f = [int(i) for i in input().split()]
print(['No','Yes'][abs(f[1] - f[0]) == 1 and (f[1] - 1) // 3 == (f[0] - 1) // 3])